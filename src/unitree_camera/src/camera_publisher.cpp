#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <std_msgs/Header.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include "UnitreeCameraSDK.hpp"
// #include "depth_publisher.hpp"
#include <unistd.h>
#include <yaml-cpp/yaml.h>

#define LEFT false
#define RIGHT true

class CameraPublisher
{
private:
    UnitreeCamera *cam;

    ros::NodeHandle node_handle;
    image_transport::ImageTransport it;

    image_transport::CameraPublisher pub_raw_left;
    image_transport::CameraPublisher pub_raw_right;
    image_transport::CameraPublisher pub_rect_left;
    image_transport::CameraPublisher pub_rect_right;
    sensor_msgs::CameraInfo camera_info_l;
    sensor_msgs::CameraInfo camera_info_r;

    // std::unique_ptr<DepthPublisher> point_cloud_pub;
    ros::Publisher pub_depth;

    std::string frame_id = "";
    bool enable_depth, enable_raw, enable_rect, enable_point_cloud;
    ros::Timer timer;
    // const std::string DEPTH_ENCODING = "8UC3";
    const std::string DEPTH_ENCODING = "bgr8";
    const std::string COLOR_ENCODING = "bgr8";
    const std::string CALIB_FILE = "calib_params.yaml";

    int count = 0;

public:
    CameraPublisher() : node_handle(), it(node_handle)
    {
        int device_node, frame_width, frame_height;
        float fps, offset_time;

        // Default device: /dev/video0
        node_handle.param<int>("device_node", device_node, 0);
        node_handle.param<std::string>("frame_id", frame_id, "");
        node_handle.param<int>("frame_width", frame_width, 1856);
        node_handle.param<int>("frame_height", frame_height, 800);
        node_handle.param<float>("fps", fps, 30.0);
        node_handle.param<float>("offset_time", offset_time, 0.);

        node_handle.param<bool>("enable_depth", enable_depth, false);
        node_handle.param<bool>("enable_raw", enable_raw, false);
        node_handle.param<bool>("enable_rect", enable_rect, true);
        node_handle.param<bool>("enable_point_cloud", enable_point_cloud, false);

        ROS_INFO_STREAM("Starting camera with device node : " << device_node);
        cam = new UnitreeCamera(device_node);

        if (!cam->isOpened())
        {
            std::string msg = "Failed to open camera";
            ROS_ERROR_STREAM(msg);
            throw std::runtime_error(msg);
        }

        cv::Size frame_size = cv::Size(frame_width, frame_height);

        if (enable_raw)
        {
            cam->setRawFrameSize(frame_size);
            cam->setRawFrameRate(fps);
            pub_raw_left = it.advertiseCamera("image/raw/left", 10);
            pub_raw_right = it.advertiseCamera("image/raw/right", 10);
        }
        if (enable_rect)
        {
            cam->setRectFrameSize(frame_size);
            pub_rect_left = it.advertiseCamera("image/rect/left", 10);
            pub_rect_right = it.advertiseCamera("image/rect/right", 10);
        }
        if (enable_depth)
        {
            pub_depth = node_handle.advertise<sensor_msgs::Image>("image/depth", 10);
        }
        // if (enable_point_cloud)
        // {
        //     point_cloud_pub = std::make_unique<DepthPublisher>(offset_time, *cam, node_handle);
        // }

        timer = node_handle.createTimer<CameraPublisher>(ros::Duration(1 / fps), &CameraPublisher::timer_callback, this);

        ROS_INFO_STREAM("Device Position Number: " << cam->getPosNumber());
        cam->startCapture();

        std::vector<cv::Mat> calib_left, calib_right;
        if (!cam->getCalibParams(calib_left, LEFT))
        {
            std::string msg = "Failed to read left camera calibration parameters";
            ROS_ERROR_STREAM(msg);
            throw std::runtime_error(msg);
        }
        if (!cam->getCalibParams(calib_right, RIGHT))
        {
            std::string msg = "Failed to read right camera calibration parameters";
            ROS_ERROR_STREAM(msg);
            throw std::runtime_error(msg);
        }
        init_camera_info(calib_left, calib_right);

        if (enable_depth || enable_point_cloud)
        {
            cam->startStereoCompute();
        }
        ROS_INFO_STREAM("camera_publisher node started");
    }

    ~CameraPublisher()
    {
        if (enable_depth || enable_point_cloud)
        {
            cam->stopStereoCompute();
        }
        cam->stopCapture();
        delete cam;
        // if (!enable_point_cloud)
        //     delete cam;
    }

private:
    void init_camera_info(std::vector<cv::Mat> calib_left, std::vector<cv::Mat> calib_right)
    {
        cv::Size raw_size = cam->getRawFrameSize();
        std::vector<double> lk(calib_left[0].reshape(1, 1));
        boost::array<double, 9> left_intrinsics;
        std::copy(lk.begin(), lk.end(), left_intrinsics.begin());

        std::vector<double> rk(calib_right[0].reshape(1, 1));
        boost::array<double, 9> right_intrinsics;
        std::copy(rk.begin(), rk.end(), right_intrinsics.begin());

        std::vector<double> lr(calib_left[3].reshape(1, 1));
        boost::array<double, 9> left_rect;
        std::copy(lr.begin(), lr.end(), left_rect.begin());

        std::vector<double> rr(calib_right[3].reshape(1, 1));
        boost::array<double, 9> right_rect;
        std::copy(rr.begin(), rr.end(), right_rect.begin());

        // std::vector<double> lp(calib_left[5]);
        // boost::array<double, 12> left_P;
        // std::copy(lp.begin(), lp.end(), left_P.begin());

        // std::vector<double> rp(calib_right[5]);
        // boost::array<double, 12> right_p;
        // std::copy(rp.begin(), rp.end(), right_p.begin());
        // Left camera info
        camera_info_l.width = raw_size.width / 2;
        camera_info_l.height = raw_size.height;
        camera_info_l.K = left_intrinsics;
        camera_info_l.R = left_rect;
        // camera_info_l.P         = left_P;

        // Right camera info
        camera_info_r.width = raw_size.width / 2;
        camera_info_r.height = raw_size.height;
        camera_info_r.K = right_intrinsics;
        camera_info_r.R = right_rect;
        // camera_info_r.P         = right_p;
    }

    void timer_callback(const ros::TimerEvent &)
    {
        ROS_DEBUG_STREAM("Publishing frames");
        if (!cam->isOpened())
        {
            std::string msg = "Camera closed unexpectedly";
            ROS_ERROR_STREAM(msg);
            throw std::runtime_error(msg);
        }
        cv::Mat frame, left, right;
        std::chrono::microseconds time;

        ros::Time current_time;
        current_time = ros::Time::now();

        std_msgs::Header header;

        header.seq = this->count++;
        header.stamp = current_time;
        header.frame_id = frame_id;

        camera_info_l.header = header;
        camera_info_r.header = header;

        if (enable_raw)
        {
            if (cam->getRawFrame(frame, time))
            {
                // frame(cv::Rect(0, 0, frame.size().width / 2, frame.size().height)).copyTo(left);
                // frame(cv::Rect(frame.size().width / 2, 0, frame.size().width / 2, frame.size().height)).copyTo(right);

                sensor_msgs::ImagePtr msg_left = cv_bridge::CvImage(
                                                     header,
                                                     COLOR_ENCODING,
                                                     frame(cv::Rect(0, 0, frame.size().width / 2, frame.size().height)))
                                                     .toImageMsg();
                sensor_msgs::ImagePtr msg_right = cv_bridge::CvImage(
                                                     header,
                                                     COLOR_ENCODING,
                                                     frame(cv::Rect(frame.size().width / 2, 0, frame.size().width / 2, frame.size().height)))
                                                     .toImageMsg();
                // ROS_INFO_STREAM("Publishing raw frames");

                pub_raw_left.publish(*msg_left, camera_info_l);
                pub_raw_right.publish(*msg_right, camera_info_r);
            }
        }

        if (enable_rect)
        {
            cv::Mat feim;
            if (cam->getRectStereoFrame(left, right, feim))
            {
                cv::flip(left, left, -1);
                cv::flip(right, right, -1);
                sensor_msgs::ImagePtr msg_left = cv_bridge::CvImage(header, COLOR_ENCODING, left).toImageMsg();
                sensor_msgs::ImagePtr msg_right = cv_bridge::CvImage(header, COLOR_ENCODING, right).toImageMsg();
                // ROS_INFO_STREAM("Publishing rectified frames");
                pub_rect_left.publish(*msg_left, camera_info_l);
                pub_rect_right.publish(*msg_right, camera_info_r);
            }
        }

        if (enable_depth)
        {
            if (cam->getDepthFrame(frame, true, time))
            {
                if (!frame.empty())
                {
                    // ROS_INFO_STREAM("Publishing depth frames");
                    sensor_msgs::ImagePtr depth_msg = cv_bridge::CvImage(header, DEPTH_ENCODING, frame).toImageMsg();
                    pub_depth.publish(*depth_msg);
                }
            }
        }

        // if (enable_point_cloud)
        // {
        //     // ROS_INFO_STREAM("Publishing point clouds");
        //     point_cloud_pub->publish();
        // }
    }
};

int main(int argc, char **argv)
{
    std::cout << cv::getBuildInformation() << std::endl;
    ros::init(argc, argv, "camera_publisher");

    CameraPublisher cam_pub;
    ros::spin();

    return 0;
}
