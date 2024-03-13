// #include <memory>
// #include <string>
// #include <vector>
// #include <exception>
// #include <ros/ros.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <sensor_msgs/Image.h>
// #include <sensor_msgs/CameraInfo.h>
// #include <std_msgs/Header.h>
// #include <cv_bridge/cv_bridge.h>
// #include <image_transport/image_transport.h>
// #include "UnitreeCameraSDK.hpp"
// #include "depth_publisher.hpp"

// class ImgPublisher
// {
// public:
//     ImgPublisher() : nodeHandle("~")
//     {

//         // Parameters
//         nodeHandle.param("fps", fps_, 30);
//         interval_ = 1.0 / static_cast<double>(fps_);
//         interval_ms_ = static_cast<std::chrono::milliseconds>(static_cast<int>(interval_ * 1000.0));
//         int device_node_, frame_height_, frame_width_;
//         double offsetTime;
//         bool use_yaml_;
//         std::string yaml_path_;
//         nodeHandle.param<int>("device_node", device_node_, 0);
//         nodeHandle.param<int>("frame_width", frame_width_, 1856);
//         nodeHandle.param<int>("frame_height", frame_height_, 800);

//         nodeHandle.param<bool>("use_yaml", use_yaml_, false);
//         nodeHandle.param<std::string>("yaml_path", yaml_path_, "");

//         nodeHandle.param<bool>("enable_raw", enable_raw, false);
//         nodeHandle.param<bool>("enable_rect", enable_rect, true);
//         nodeHandle.param<bool>("enable_depth", enable_depth, false);
//         nodeHandle.param<bool>("enable_point_cloud", enable_point_cloud, false);

//         nodeHandle.param<double>("offset_time", offsetTime, 0.0);

//         if (use_yaml_ && (yaml_path_ == ""))
//         {
//             std::string msg = "Must specify yaml configuration file path to use one.";
//             ROS_ERROR_STREAM(msg);
//             throw std::logic_error(msg);
//         }

//         // Timers
//         timer_ = nodeHandle.createTimer(ros::Duration(interval_), boost::bind(&ImgPublisher::timer_callback, this, _1));

//         frame_size_ = cv::Size{frame_width_, frame_height_};

//         // Initialize camera
//         if (!use_yaml_)
//         {
//             cam = new UnitreeCamera(device_node_);
//         }
//         else
//         {
//             cam = new UnitreeCamera(yaml_path_);
//         }

//         // Throw error and exit if camera fails to open
//         if (!cam->isOpened())
//         {
//             std::string msg = "Camera failed to open on startup.";
//             ROS_ERROR_STREAM(msg);
//             throw std::logic_error(msg);
//         }

//         // Set frame size and fps
//         if (!use_yaml_)
//         {
//             cam->setRawFrameSize(frame_size_);
//             cam->setRawFrameRate(fps_);
//         }

//         if (enable_raw)
//         {
//             pub_raw_left = it_.advertiseCamera("~/image_raw/left", 10);
//             pub_raw_right = it_.advertiseCamera("~/image_raw/right", 10);
//         }

//         if (enable_rect)
//         {
//             if (!use_yaml_)
//             {
//                 cam->setRectFrameSize(cv::Size(frame_size_.width >> 2, frame_size_.height >> 1));
//             }

//             pub_rect_left = it_.advertiseCamera("~/image_rect/left", 10);
//             pub_rect_right = it_.advertiseCamera("~/image_rect/right", 10);
//         }

//         if (enable_depth)
//         {
//             pub_depth_ = nodeHandle.advertise<sensor_msgs::Image>("~/image_depth", 10);
//         }

//         if (enable_point_cloud) {
//             point_cloud_pub = new DepthPublisher(offsetTime, cam, nodeHandle);
//         }

//         ROS_INFO_STREAM("Device Position Number: " << cam->getPosNumber());

//         // Start camera capturing
//         cam->startCapture();
//         if (enable_depth || enable_point_cloud)
//         {
//             cam->startStereoCompute();
//         }

//         ROS_INFO_STREAM("img_publisher node started");
//     }

//     // Stop capture when node is destroyed
//     ~ImgPublisher()
//     {
//         delete point_cloud_pub;
//         if (enable_depth || enable_point_cloud)
//         {
//             cam->stopStereoCompute();
//         }
//         cam->stopCapture();
//     }

// private:
//     DepthPublisher *point_cloud_pub;

//     ros::NodeHandle nodeHandle;
//     image_transport::ImageTransport it_{nodeHandle};
//     ros::Timer timer_;
//     image_transport::CameraPublisher pub_raw_left;
//     image_transport::CameraPublisher pub_raw_right;
//     image_transport::CameraPublisher pub_rect_left;
//     image_transport::CameraPublisher pub_rect_right;
//     ros::Publisher pub_depth_;

//     double interval_;
//     std::chrono::milliseconds interval_ms_;
//     int fps_;
//     bool enable_raw, enable_rect, enable_depth, enable_point_cloud;
//     std::string point_cloud_frame_;
//     cv::Size frame_size_{1856, 800};
//     const std::string color_encoding_ = "bgr8";
//     const std::string depth_encoding_ = "8UC3";
//     sensor_msgs::CameraInfo camera_info_; // unsure how to get this from UnitreeCameraSDK

//     UnitreeCamera *cam;

//     void timer_callback(const ros::TimerEvent &)
//     {
//         // Throw error and exit if camera is no longer open
//         if (!cam->isOpened())
//         {
//             std::string msg = "Camera closed unexpectedly.";
//             ROS_ERROR_STREAM(msg);
//             throw std::logic_error(msg);
//         }

//         std_msgs::Header header;
//         header.stamp = ros::Time::now();
//         camera_info_.header = header;

//         std::chrono::microseconds t;

//         // Get and publish raw frames
//         if (enable_raw)
//         {
//             cv::Mat raw_frame;

//             // Process/publish raw frame if it can be obtained
//             if (cam->getRawFrame(raw_frame, t))
//             {
//                 cv::Mat raw_left, raw_right;

//                 // Get left and right images from returned frame
//                 raw_frame(cv::Rect(raw_frame.size().width / 2, 0, raw_frame.size().width / 2, raw_frame.size().height))
//                     .copyTo(raw_left);
//                 raw_frame(cv::Rect(0, 0, raw_frame.size().width / 2, raw_frame.size().height))
//                     .copyTo(raw_right);

//                 // Publish frames
//                 sensor_msgs::ImagePtr msg_raw_left = cv_bridge::CvImage(header, color_encoding_, raw_left).toImageMsg();
//                 msg_raw_left->header = header;
//                 pub_raw_left.publish(*msg_raw_left, camera_info_);

//                 sensor_msgs::ImagePtr msg_raw_right = cv_bridge::CvImage(header, color_encoding_, raw_right).toImageMsg();
//                 msg_raw_right->header = header;
//                 pub_raw_right.publish(*msg_raw_right, camera_info_);
//             }
//         }

//         // Get and publish rectified frames
//         if (enable_rect)
//         {
//             cv::Mat rect_left, rect_right;

//             if (cam->getRectStereoFrame(rect_left, rect_right))
//             {
//                 // flip frames
//                 cv::flip(rect_left, rect_left, -1);
//                 cv::flip(rect_right, rect_right, -1);

//                 // Publish frames
//                 sensor_msgs::ImagePtr msg_rect_left = cv_bridge::CvImage(header, color_encoding_, rect_left).toImageMsg();
//                 msg_rect_left->header = header;
//                 pub_rect_left.publish(*msg_rect_left, camera_info_);

//                 sensor_msgs::ImagePtr msg_rect_right = cv_bridge::CvImage(header, color_encoding_, rect_right).toImageMsg();
//                 msg_rect_right->header = header;
//                 pub_rect_right.publish(*msg_rect_right, camera_info_);
//             }
//         }

//         // Get and publish depth frames
//         if (enable_depth)
//         {
//             cv::Mat depth;

//             if (cam->getDepthFrame(depth, true, t))
//             {
//                 if (!depth.empty())
//                 {
//                     // Publish frames
//                     sensor_msgs::ImagePtr msg_depth = cv_bridge::CvImage(header, depth_encoding_, depth).toImageMsg();
//                     msg_depth->header = header;
//                     pub_depth_.publish(msg_depth);
//                 }
//             }
//         }

//         if (enable_point_cloud) {
//             point_cloud_pub->runOnce();
//         }
//     }
// };

// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "camera_publisher");
//     ImgPublisher img_publisher;
//     ros::spin();
//     return 0;
// }

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <std_msgs/Header.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include "UnitreeCameraSDK.hpp"
#include "depth_publisher.hpp"

// image_transport::CameraPublisher pub_raw_left;
// image_transport::CameraPublisher pub_raw_right;
// image_transport::CameraPublisher pub_rect_left;
// image_transport::CameraPublisher pub_rect_right;
// ros::Publisher pub_depth_;
// DepthPublisher *point_cloud_pub;

// void publishAll(UnitreeCamera *cam, bool enable_raw, bool enable_rect, bool enable_depth, bool enable_point_cloud)
// {
//     // Throw error and exit if camera is no longer open
//     if (!cam->isOpened())
//     {
//         std::string msg = "Camera closed unexpectedly.";
//         ROS_ERROR_STREAM(msg);
//         throw std::logic_error(msg);
//     }

//     const std::string color_encoding_ = "bgr8";
//     const std::string depth_encoding_ = "8UC3";
//     std_msgs::Header header;
//     sensor_msgs::CameraInfo camera_info_;
//     header.stamp = ros::Time::now();
//     camera_info_.header = header;

//     std::chrono::microseconds t;

//     // Get and publish raw frames
//     if (enable_raw)
//     {
//         cv::Mat raw_frame;

//         // Process/publish raw frame if it can be obtained
//         if (cam->getRawFrame(raw_frame, t))
//         {
//             cv::Mat raw_left, raw_right;

//             // Get left and right images from returned frame
//             raw_frame(cv::Rect(raw_frame.size().width / 2, 0, raw_frame.size().width / 2, raw_frame.size().height))
//                 .copyTo(raw_left);
//             raw_frame(cv::Rect(0, 0, raw_frame.size().width / 2, raw_frame.size().height))
//                 .copyTo(raw_right);

//             // Publish frames
//             sensor_msgs::ImagePtr msg_raw_left = cv_bridge::CvImage(header, color_encoding_, raw_left).toImageMsg();
//             msg_raw_left->header = header;
//             pub_raw_left.publish(*msg_raw_left, camera_info_);

//             sensor_msgs::ImagePtr msg_raw_right = cv_bridge::CvImage(header, color_encoding_, raw_right).toImageMsg();
//             msg_raw_right->header = header;
//             pub_raw_right.publish(*msg_raw_right, camera_info_);
//         }
//     }

//     // Get and publish rectified frames
//     if (enable_rect)
//     {
//         cv::Mat rect_left, rect_right;

//         if (cam->getRectStereoFrame(rect_left, rect_right))
//         {
//             // flip frames
//             cv::flip(rect_left, rect_left, -1);
//             cv::flip(rect_right, rect_right, -1);

//             // Publish frames
//             sensor_msgs::ImagePtr msg_rect_left = cv_bridge::CvImage(header, color_encoding_, rect_left).toImageMsg();
//             msg_rect_left->header = header;
//             pub_rect_left.publish(*msg_rect_left, camera_info_);

//             sensor_msgs::ImagePtr msg_rect_right = cv_bridge::CvImage(header, color_encoding_, rect_right).toImageMsg();
//             msg_rect_right->header = header;
//             pub_rect_right.publish(*msg_rect_right, camera_info_);
//         }
//     }

//     // Get and publish depth frames
//     if (enable_depth)
//     {
//         cv::Mat depth;

//         if (cam->getDepthFrame(depth, true, t))
//         {
//             if (!depth.empty())
//             {
//                 // Publish frames
//                 sensor_msgs::ImagePtr msg_depth = cv_bridge::CvImage(header, depth_encoding_, depth).toImageMsg();
//                 msg_depth->header = header;
//                 pub_depth_.publish(msg_depth);
//             }
//         }
//     }

//     if (enable_point_cloud)
//     {
//         point_cloud_pub->runOnce();
//     }
// }

int main(int argc, char **argv)
{
    // std::cout << cv::getBuildInformation() << std::endl;
    // ros::init(argc, argv, "camera_publisher");

    // ros::NodeHandle nodeHandle("~");
    // image_transport::ImageTransport it_{nodeHandle};

    // double interval_;
    // std::chrono::milliseconds interval_ms_;
    // int fps_;
    // bool enable_raw, enable_rect, enable_depth, enable_point_cloud;
    // std::string point_cloud_frame_;
    // cv::Size frame_size_{1856, 800};

    // // Parameters
    // int fps, device_node, frame_height, frame_width;
    // double offsetTime;
    // bool use_yaml;
    // std::string yaml_path;

    // nodeHandle.param("fps", fps, 30);
    // interval_ = 1.0 / static_cast<double>(fps);
    // interval_ms_ = static_cast<std::chrono::milliseconds>(static_cast<int>(interval_ * 1000.0));

    // nodeHandle.param<int>("device_node", device_node, 0);
    // nodeHandle.param<int>("frame_width", frame_width, 1856);
    // nodeHandle.param<int>("frame_height", frame_height, 800);

    // nodeHandle.param<bool>("use_yaml", use_yaml, true);
    // nodeHandle.param<std::string>("yaml_path", yaml_path, "src/unitree_camera_config/camera_config0.yaml");

    // nodeHandle.param<bool>("enable_raw", enable_raw, false);
    // nodeHandle.param<bool>("enable_rect", enable_rect, true);
    // nodeHandle.param<bool>("enable_depth", enable_depth, false);
    // nodeHandle.param<bool>("enable_point_cloud", enable_point_cloud, false);

    // nodeHandle.param<double>("offset_time", offsetTime, 0.0);

    // if (use_yaml && yaml_path.empty())
    // {
    //     std::string msg = "Must specify yaml configuration file path to use one.";
    //     ROS_ERROR_STREAM(msg);
    //     throw std::logic_error(msg);
    // }
    bool use_yaml = true;

    // frame_size_ = cv::Size{frame_width, frame_height};

    // Initialize camera
    if (!use_yaml)
    {
        // UnitreeCamera cam(device_node);
        // // Throw error and exit if camera fails to open
        // if (!cam.isOpened())
        // {
        //     std::string msg = "Camera failed to open on startup.";
        //     ROS_ERROR_STREAM(msg);
        //     throw std::logic_error(msg);
        // }

        // // Set frame size and fps
        // if (!use_yaml)
        // {
        //     cam.setRawFrameSize(frame_size_);
        //     cam.setRawFrameRate(fps);
        // }

        // if (enable_raw)
        // {
        //     pub_raw_left = it_.advertiseCamera("~/image_raw/left", 10);
        //     pub_raw_right = it_.advertiseCamera("~/image_raw/right", 10);
        // }

        // if (enable_rect)
        // {
        //     if (!use_yaml)
        //     {
        //         cam.setRectFrameSize(cv::Size(frame_size_.width >> 2, frame_size_.height >> 1));
        //     }

        //     pub_rect_left = it_.advertiseCamera("~/image_rect/left", 10);
        //     pub_rect_right = it_.advertiseCamera("~/image_rect/right", 10);
        // }

        // if (enable_depth)
        // {
        //     pub_depth_ = nodeHandle.advertise<sensor_msgs::Image>("~/image_depth", 10);
        // }

        // if (enable_point_cloud)
        // {
        //     point_cloud_pub = new DepthPublisher(offsetTime, &cam, nodeHandle);
        // }

        // ROS_INFO_STREAM("Device Position Number: " << cam.getPosNumber());

        // // Start camera capturing
        // cam.startCapture();
        // if (enable_depth || enable_point_cloud)
        // {
        //     cam.startStereoCompute();
        // }
        // ROS_INFO_STREAM("img_publisher node started");
        // while (ros::ok() && cam.isOpened())
        // {
        //     publishAll(&cam, enable_raw, enable_rect, enable_depth, enable_point_cloud);
        // }
        // delete point_cloud_pub;
        // if (enable_depth || enable_point_cloud)
        // {
        //     cam.stopStereoCompute();
        // }
        // cam.stopCapture();
    }
    else
    {
        UnitreeCamera cam("src/unitree_camera/config/camera_config0.yaml");
        // // Throw error and exit if camera fails to open
        if (!cam.isOpened())
        {
            std::string msg = "Camera failed to open on startup.";
            ROS_ERROR_STREAM(msg);
            throw std::logic_error(msg);
        }

        // // Set frame size and fps
        // if (!use_yaml)
        // {
        //     cam.setRawFrameSize(frame_size_);
        //     cam.setRawFrameRate(fps);
        // }

        // if (enable_raw)
        // {
        //     pub_raw_left = it_.advertiseCamera("~/image_raw/left", 10);
        //     pub_raw_right = it_.advertiseCamera("~/image_raw/right", 10);
        // }

        // if (enable_rect)
        // {
        //     if (!use_yaml)
        //     {
        //         cam.setRectFrameSize(cv::Size(frame_size_.width >> 2, frame_size_.height >> 1));
        //     }

        //     pub_rect_left = it_.advertiseCamera("~/image_rect/left", 10);
        //     pub_rect_right = it_.advertiseCamera("~/image_rect/right", 10);
        // }

        // if (enable_depth)
        // {
        //     pub_depth_ = nodeHandle.advertise<sensor_msgs::Image>("~/image_depth", 10);
        // }

        // if (enable_point_cloud)
        // {
        //     point_cloud_pub = new DepthPublisher(offsetTime, &cam, nodeHandle);
        // }

        // ROS_INFO_STREAM("Device Position Number: " << cam.getPosNumber());

        // // Start camera capturing
        // cam.startCapture();
        // if (enable_depth || enable_point_cloud)
        // {
        //     cam.startStereoCompute();
        // }
        // ROS_INFO_STREAM("img_publisher node started");
        // while (ros::ok() && cam.isOpened())
        // {
        //     publishAll(&cam, enable_raw, enable_rect, enable_depth, enable_point_cloud);
        //     // ros::spinOnce();
        // }
        // delete point_cloud_pub;
        // if (enable_depth || enable_point_cloud)
        // {
        //     cam.stopStereoCompute();
        // }
        cam.stopCapture();
    }

    return 0;
}
