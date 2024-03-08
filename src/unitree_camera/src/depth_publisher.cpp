#include <iostream>
#include <signal.h>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Range.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <pcl/filters/crop_box.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <UnitreeCameraSDK.hpp>

#include "depth_publisher.hpp"

DepthPublisher::DepthPublisher(double offsetTime, std::shared_ptr<UnitreeCamera> cam_, ros::NodeHandle nodeHandle_) : nodeHandle(nodeHandle_), offsetTime_(offsetTime), cam(cam_)
{
    init();
}

DepthPublisher::~DepthPublisher()
{
    cleanup();
}

void DepthPublisher::runOnce()
{
    std::chrono::microseconds timeStamp;
    std::vector<PCLType> curPCL;

    if (!cam->getPointCloud(curPCL, timeStamp))
    {
        usleep(1000);
        return;
    }

    if (camPosNum == 2)
    {
        sleep(0.005);
        return;
    }

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    processPointCloud(curPCL, cloud);

    publishPointCloud(cloud, timeStamp);
    publishRanges(cloud, timeStamp);
}

void DepthPublisher::run()
{
    while (ros::ok() && cam->isOpened())
    {
        runOnce();
        ros::spinOnce();
    }
}

void DepthPublisher::init()
{
    camPosNum = cam->getPosNumber();
    frameIdName = "trunk";
    pointCloudName = "point_cloud_";
    rangeName = "range_visual_";

    initCamera();
}

void DepthPublisher::cleanup()
{
    cam->stopStereoCompute();
}

void DepthPublisher::processPointCloud(const std::vector<PCLType> &curPCL, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud)
{
    cv::Mat vectorInCamFrame = (cv::Mat_<float>(4, 1) << 0, 0, 0, 1);
    cv::Mat vectorInBodyFrame = (cv::Mat_<float>(4, 1) << 0, 0, 0, 1);

    for (const auto &pclType : curPCL)
    {
        pcl::PointXYZRGB point;
        vectorInCamFrame.at<float>(0, 0) = pclType.pts(0);
        vectorInCamFrame.at<float>(1, 0) = pclType.pts(1);
        vectorInCamFrame.at<float>(2, 0) = pclType.pts(2);

        vectorInBodyFrame = rotationCamToBody_ * vectorInCamFrame;
        point.x = (vectorInBodyFrame.at<float>(0, 0) + translationCamToBody_.at<float>(0, 0));
        point.y = (vectorInBodyFrame.at<float>(1, 0) + translationCamToBody_.at<float>(1, 0));
        point.z = (vectorInBodyFrame.at<float>(2, 0) + translationCamToBody_.at<float>(2, 0));

        filterPointCloud(point, pclType, cloud);
    }

    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(30);

    if (camPosNum == 1)
        sor.setStddevMulThresh(1.0f);
    else
        sor.setStddevMulThresh(1.0f);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);
    sor.filter(*cloud_filtered);
    cloud = cloud_filtered;
}

void DepthPublisher::filterPointCloud(pcl::PointXYZRGB &point, const PCLType &pclType, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud)
{
    float px = pclType.pts(0);
    float py = pclType.pts(1);
    float pz = pclType.pts(2);

    if (camPosNum == 1)
    {
        if (point.z > 0.15)
            return;
        if (px < 0.05)
            return;
        if (std::abs(px / py) < std::tan(M_PI / 180.0 * 40.0)) // range of 100
            return;
        if (!(py < 0.5 && py > -0.5))
            return;
    }
    else if (camPosNum == 2)
    {
        float tanPtx = std::abs(pz / px);
        float tanPty = std::abs(pz / py);
        if (tanPtx < tanTheta_ || tanPty < tanTheta_ || (tanPtx < tanBk_ && px < 0))
            return;
    }
    else if (camPosNum == 3)
    {                                                                            // left
        if (point.z > 0.15 || std::abs(py / px) < std::tan(M_PI / 180.0 * 40.0)) // range of 100
            return;
        if (!(py > 0.1 && px < 0.35 && px > -0.35))
            return;
    }
    else if (camPosNum == 4)
    {                                                                            // right
        if (point.z > 0.15 || std::abs(py / px) < std::tan(M_PI / 180.0 * 40.0)) // range of 100
            return;
        if (!(py < -0.1 && px < 0.35 && px > -0.35))
            return;
    }
    else if (camPosNum == 5)
    {
        if (std::abs(pz / py) < tanTheta_ || std::abs(pz / px) < tanTheta_)
            return;
        if (!(point.z < -0.05 && point.y >= -0.35 && point.y <= 0.35 && point.x < 0.80 && point.x > -0.8))
            return;
    }

    point.r = pclType.clr(2);
    point.g = pclType.clr(1);
    point.b = pclType.clr(0);
    cloud->points.push_back(point);
}

void DepthPublisher::publishPointCloud(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp)
{
    sensor_msgs::PointCloud2 cloud_publish_msg;
    pcl::toROSMsg(*cloud, cloud_publish_msg);
    cloud_publish_msg.header.frame_id = "trunk";
    ros::Time::now();
    cloud_publish_msg.header.stamp = ros::Time(timeStamp.count() / 1000000.0 + offsetTime_);
    topic_publisher_.publish(cloud_publish_msg);
}

void DepthPublisher::publishRanges(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp)
{
    float dmin = 2.0f;
    switch (camPosNum)
    {
    case 1:
        for (size_t i = 0; i < cloud->size(); i++)
        {
            if (std::fabs(cloud->at(i).z + 0.3) > 0.2 && cloud->at(i).x < dmin)
                dmin = cloud->at(i).x;
        }

        publishRange(cloud, timeStamp, dmin - 0.2747, "camera_face");
        break;
    case 3:
        for (size_t i = 0; i < cloud->size(); i++)
        {
            if (std::fabs(cloud->at(i).z + 0.3) > 0.2 && std::fabs(cloud->at(i).y) < dmin)
                dmin = std::fabs(cloud->at(i).y);
        }
        publishRange(cloud, timeStamp, dmin - 0.0826, "camera_left");
        // publishLeftRange(cloud);
        break;
    case 4:
        for (size_t i = 0; i < cloud->size(); i++)
        {
            if (std::fabs(cloud->at(i).z + 0.3) > 0.15 && std::fabs(cloud->at(i).y) < dmin)
                dmin = std::fabs(cloud->at(i).y);
        }
        publishRange(cloud, timeStamp, dmin - 0.0826, "camera_right");
        // publishRightRange(cloud);
        break;
    }
}

void DepthPublisher::publishRange(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp, float r, const char *frame_id)
{
    sensor_msgs::Range range;
    range.range = r;
    range.field_of_view = 90.0 / 180.0 * M_PI;
    range.min_range = 0.05;
    range.max_range = 2.0;
    range.radiation_type = sensor_msgs::Range::ULTRASOUND;
    range.header.frame_id = frame_id;
    range.header.stamp = ros::Time(timeStamp.count() / 1000000.0 + offsetTime_);
    range_publisher_.publish(range);
}

void DepthPublisher::initCamera()
{
    if (camPosNum != 2)
    {
        cam->startStereoCompute();

        switch (camPosNum)
        {
        case 1:
            pointCloudName += "face";
            rangeName += "face";
            break;
        case 2:
            pointCloudName += "chin";
            break;
        case 3:
            pointCloudName += "left";
            rangeName += "left";
            break;
        case 4:
            pointCloudName += "right";
            rangeName += "right";
            break;
        case 5:
            pointCloudName += "rearDown";
            break;
        default:
            break;
        }

        std::cout << "Camera PositionNumber -> " << camPosNum << " Point Cloud Name ->" << pointCloudName << std::endl;

        setupTransformationMatrices();

        topic_publisher_ = nodeHandle.advertise<sensor_msgs::PointCloud2>(pointCloudName, 1);

        if (camPosNum == 1 || camPosNum == 3 || camPosNum == 4)
            range_publisher_ = nodeHandle.advertise<sensor_msgs::Range>(rangeName, 1);
    }
}

void DepthPublisher::setupTransformationMatrices()
{
    switch (camPosNum)
    {
    case 1:
        theta_ = 2.0 * M_PI / 3.0 + M_PI / 18;
        tanTheta_ = std::tan((M_PI - theta_) / 2);
        translationCamToBody_ = (cv::Mat_<float>(3, 1) << 0.28, 0.010, 0.0536);
        rotationCamToBody_ = getTranslationMatrix('x', M_PI) * getTranslationMatrix('y', M_PI / 2.0) * getTranslationMatrix('z', -M_PI / 2);
        break;
    case 2:
        theta_ = 2.0 * M_PI / 3.0 + M_PI / 18;
        tanBk_ = std::tan(M_PI / 4 - M_PI / 16);
        tanTheta_ = std::tan((M_PI - theta_) / 2);
        translationCamToBody_ = (cv::Mat_<float>(3, 1) << 0.287, 0.010, -0.0046);
        rotationCamToBody_ = getTranslationMatrix('z', M_PI) * getTranslationMatrix('y', -M_PI / 48) * getTranslationMatrix('y', M_PI) * getTranslationMatrix('z', -M_PI / 2);
        break;
    case 3:
        tanTheta_ = std::tan(M_PI / 2.5);
        translationCamToBody_ = (cv::Mat_<float>(3, 1) << -0.0135, 0.080, 0.0136);
        rotationCamToBody_ = getTranslationMatrix('y', M_PI) * getTranslationMatrix('x', -(M_PI / 2 - M_PI / 16));
        break;
    case 4:
        theta_ = M_PI * 5.0 / 6.0 - M_PI * 2 / 9;
        tanTheta_ = std::tan((M_PI - theta_) / 2.0);
        translationCamToBody_ = (cv::Mat_<float>(3, 1) << -0.0105, -0.080, 0.0236);
        rotationCamToBody_ = getTranslationMatrix('y', M_PI) * getTranslationMatrix('x', (M_PI / 2.0 - M_PI / 16.0)) * getTranslationMatrix('z', M_PI);
        break;
    case 5:
        theta_ = M_PI * 2.0 / 3.0;
        tanTheta_ = std::tan((M_PI - theta_) / 2.0);
        translationCamToBody_ = (cv::Mat_<float>(3, 1) << -0.0505, 0, -0.0055);
        rotationCamToBody_ = getTranslationMatrix('x', M_PI) * getTranslationMatrix('z', -M_PI / 2);
        break;
    default:
        break;
    }
}

cv::Mat DepthPublisher::getTranslationMatrix(char axis, float angle)
{
    cv::Mat mat(4, 4, CV_32FC1, cv::Scalar(0));

    if (axis == 'x')
    {
        mat.at<float>(0, 0) = 1.0;
        mat.at<float>(1, 1) = std::cos(angle);
        mat.at<float>(1, 2) = -std::sin(angle);
        mat.at<float>(2, 1) = std::sin(angle);
        mat.at<float>(2, 2) = std::cos(angle);
        mat.at<float>(3, 3) = 1.0;
    }
    else if (axis == 'y')
    {
        mat.at<float>(0, 0) = std::cos(angle);
        mat.at<float>(0, 2) = std::sin(angle);
        mat.at<float>(1, 1) = 1.0;
        mat.at<float>(2, 0) = -std::sin(angle);
        mat.at<float>(2, 2) = std::cos(angle);
        mat.at<float>(3, 3) = 1.0;
    }
    else if (axis == 'z')
    {
        mat.at<float>(0, 0) = std::cos(angle);
        mat.at<float>(0, 1) = -std::sin(angle);
        mat.at<float>(1, 0) = std::sin(angle);
        mat.at<float>(1, 1) = std::cos(angle);
        mat.at<float>(2, 2) = 1.0;
        mat.at<float>(3, 3) = 1.0;
    }

    return mat;
}

// int main(int argc, char **argv)
// {
//     std::string node_name;
//     if (argc < 3)
//     {
//         printf("Tips: if use rosrun, execute: rosrun pkgname node_executable_bin node_name _params:=value ...\n");
//         node_name = std::string("unitree_camera_node");
//     }
//     else
//     {
//         node_name = std::string(argv[2]);
//     }
//     double offsetTime = static_cast<double>(std::atof(argv[3]));
//     fprintf(stderr, "Initializing ROS");
//     ros::init(argc, argv, node_name);
//     fprintf(stderr, "ROS inited");

//     DepthPublisher node(offsetTime);
//     node.run();

//     return 0;
// }
