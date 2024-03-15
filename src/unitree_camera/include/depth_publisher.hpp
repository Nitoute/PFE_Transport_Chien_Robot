#ifndef DEPTH_PUBLISHER_H
#define DEPTH_PUBLISHER_H

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
class UnitreeCamera;

class DepthPublisher
{
public:
    DepthPublisher(double offsetTime, std::shared_ptr<UnitreeCamera>cam_, ros::NodeHandle);

    void run();
    void publish();

private:
    void init();
    void cleanup();
    void processPointCloud(const std::vector<PCLType> &curPCL, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud);
    void filterPointCloud(pcl::PointXYZRGB &point, const PCLType &pclType, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud);
    void publishPointCloud(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp);
    void publishRanges(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp);
    void publishRange(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, const std::chrono::microseconds &timeStamp, float r, const char *frame_id);
    void initCamera();
    void setupTransformationMatrices();
    cv::Mat getTranslationMatrix(char axis, float angle);

    std::shared_ptr<UnitreeCamera> cam;
    ros::NodeHandle nodeHandle;

    ros::Publisher topic_publisher_;
    ros::Publisher range_publisher_;

    std::string frameIdName;
    std::string pointCloudName;
    std::string rangeName;

    double offsetTime_;

    int camPosNum;
    float theta_;
    float tanTheta_;
    float tanBk_;
    cv::Mat translationCamToBody_;
    cv::Mat rotationCamToBody_;
};

#endif // DEPTH_PUBLISHER_H
