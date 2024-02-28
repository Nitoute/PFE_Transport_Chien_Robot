#include <memory>
#include <string>
#include <vector>
#include <exception>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <std_msgs/Header.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include "UnitreeCameraSDK.hpp"

using namespace std::chrono_literals;

class ImgPublisher
{
public:
    ImgPublisher()
    {
        // Parameters
        nh_.param("fps", fps_, 30);
        interval_ = 1.0 / static_cast<double>(fps_);
        interval_ms_ = static_cast<std::chrono::milliseconds>(static_cast<int>(interval_ * 1000.0));
        int device_node_, frame_height_, frame_width_;
        bool use_yaml_;
        std::string yaml_path_;
        nh_.param("device_node", device_node_, 0);
        nh_.param("frame_width", frame_width_, 1856);
        nh_.param("frame_height", frame_height_, 800);

        nh_.param("use_yaml", use_yaml_, false);
        nh_.param("yaml_path", yaml_path_, std::string(""));

        nh_.param("enable_raw", enable_raw_, false);
        nh_.param("enable_rect", enable_rect_, true);
        nh_.param("enable_depth", enable_depth_, false);

        if (use_yaml_ && (yaml_path_ == ""))
        {
            std::string msg = "Must specify yaml configuration file path to use one.";
            ROS_ERROR_STREAM(msg);
            throw std::logic_error(msg);
        }

        // Timers
        timer_ = nh_.createTimer(ros::Duration(interval_), boost::bind(&ImgPublisher::timer_callback, this, _1));

        frame_size_ = cv::Size{frame_width_, frame_height_};

        // Initialize camera
        if (!use_yaml_)
        {
            cam_ = std::make_unique<UnitreeCamera>(device_node_);
        }
        else
        {
            cam_ = std::make_unique<UnitreeCamera>(yaml_path_);
        }

        // Throw error and exit if camera fails to open
        if (!cam_->isOpened())
        {
            std::string msg = "Camera failed to open on startup.";
            ROS_ERROR_STREAM(msg);
            throw std::logic_error(msg);
        }

        // Set frame size and fps
        if (!use_yaml_)
        {
            cam_->setRawFrameSize(frame_size_);
            cam_->setRawFrameRate(fps_);
        }

        if (enable_raw_)
        {
            pub_raw_left_ = it_.advertiseCamera("~/image_raw/left", 10);
            pub_raw_right_ = it_.advertiseCamera("~/image_raw/right", 10);
        }

        if (enable_rect_)
        {
            if (!use_yaml_)
            {
                cam_->setRectFrameSize(cv::Size(frame_size_.width >> 2, frame_size_.height >> 1));
            }

            pub_rect_left_ = it_.advertiseCamera("~/image_rect/left", 10);
            pub_rect_right_ = it_.advertiseCamera("~/image_rect/right", 10);
        }

        if (enable_depth_)
        {
            pub_depth_ = nh_.advertise<sensor_msgs::Image>("~/image_depth", 10);
        }
        ROS_INFO_STREAM("Device Position Number: " << cam_->getPosNumber());

        // Start camera capturing
        cam_->startCapture();
        if (enable_depth_ || enable_point_cloud_)
        {
            cam_->startStereoCompute();
        }

        ROS_INFO_STREAM("img_publisher node started");
    }

    // Stop capture when node is destroyed
    ~ImgPublisher()
    {
        if (enable_depth_ || enable_point_cloud_)
        {
            cam_->stopStereoCompute();
        }
        cam_->stopCapture();
    }

private:
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_{nh_};
    ros::Timer timer_;
    image_transport::CameraPublisher pub_raw_left_;
    image_transport::CameraPublisher pub_raw_right_;
    image_transport::CameraPublisher pub_rect_left_;
    image_transport::CameraPublisher pub_rect_right_;
    ros::Publisher pub_depth_;

    double interval_;
    std::chrono::milliseconds interval_ms_;
    int fps_;
    bool enable_raw_, enable_rect_, enable_depth_, enable_point_cloud_;
    std::string point_cloud_frame_;
    cv::Size frame_size_{1856, 800};
    const std::string color_encoding_ = "bgr8";
    const std::string depth_encoding_ = "8UC3";
    sensor_msgs::CameraInfo camera_info_; // unsure how to get this from UnitreeCameraSDK

    std::unique_ptr<UnitreeCamera> cam_;

    void timer_callback(const ros::TimerEvent &)
    {
        // Throw error and exit if camera is no longer open
        if (!cam_->isOpened())
        {
            std::string msg = "Camera closed unexpectedly.";
            ROS_ERROR_STREAM(msg);
            throw std::logic_error(msg);
        }

        std_msgs::Header header;
        header.stamp = ros::Time::now();
        camera_info_.header = header;

        std::chrono::microseconds t;

        // Get and publish raw frames
        if (enable_raw_)
        {
            cv::Mat raw_frame;

            // Process/publish raw frame if it can be obtained
            if (cam_->getRawFrame(raw_frame, t))
            {
                cv::Mat raw_left, raw_right;

                // Get left and right images from returned frame
                raw_frame(cv::Rect(raw_frame.size().width / 2, 0, raw_frame.size().width / 2, raw_frame.size().height))
                    .copyTo(raw_left);
                raw_frame(cv::Rect(0, 0, raw_frame.size().width / 2, raw_frame.size().height))
                    .copyTo(raw_right);

                // Publish frames
                sensor_msgs::ImagePtr msg_raw_left = cv_bridge::CvImage(header, color_encoding_, raw_left).toImageMsg();
                msg_raw_left->header = header;
                pub_raw_left_.publish(*msg_raw_left, camera_info_);

                sensor_msgs::ImagePtr msg_raw_right = cv_bridge::CvImage(header, color_encoding_, raw_right).toImageMsg();
                msg_raw_right->header = header;
                pub_raw_right_.publish(*msg_raw_right, camera_info_);
            }
        }

        // Get and publish rectified frames
        if (enable_rect_)
        {
            cv::Mat rect_left, rect_right;

            if (cam_->getRectStereoFrame(rect_left, rect_right))
            {
                // flip frames
                cv::flip(rect_left, rect_left, -1);
                cv::flip(rect_right, rect_right, -1);

                // Publish frames
                sensor_msgs::ImagePtr msg_rect_left = cv_bridge::CvImage(header, color_encoding_, rect_left).toImageMsg();
                msg_rect_left->header = header;
                pub_rect_left_.publish(*msg_rect_left, camera_info_);

                sensor_msgs::ImagePtr msg_rect_right = cv_bridge::CvImage(header, color_encoding_, rect_right).toImageMsg();
                msg_rect_right->header = header;
                pub_rect_right_.publish(*msg_rect_right, camera_info_);
            }
        }

        // Get and publish depth frames
        if (enable_depth_)
        {
            cv::Mat depth;

            if (cam_->getDepthFrame(depth, true, t))
            {
                if (!depth.empty())
                {
                    // Publish frames
                    sensor_msgs::ImagePtr msg_depth = cv_bridge::CvImage(header, depth_encoding_, depth).toImageMsg();
                    msg_depth->header = header;
                    pub_depth_.publish(msg_depth);
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "img_publisher");
    ImgPublisher img_publisher;
    ros::spin();
    return 0;
}