#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include "unitree_legged_msgs/HighState.h"
#include <chrono>

ros::Publisher pub_imu;
ros::Publisher pub_odom;
ros::Subscriber state_sub;


float imu[4] = {0};
float position[3] = {0};
long seq = 0;

void publish_imu(const unitree_legged_msgs::HighState::ConstPtr &msg, ros::Time current_time)
{
    sensor_msgs::Imu msg_imu;

    msg_imu.header.seq = seq;
    msg_imu.header.stamp = current_time;
    msg_imu.header.frame_id = "imu_link";

    msg_imu.orientation.w = msg->imu.quaternion[0];
    msg_imu.orientation.x = msg->imu.quaternion[1];
    msg_imu.orientation.y = msg->imu.quaternion[2];
    msg_imu.orientation.z = msg->imu.quaternion[3];

    msg_imu.angular_velocity.x = msg->imu.gyroscope[0];
    msg_imu.angular_velocity.y = msg->imu.gyroscope[1];
    msg_imu.angular_velocity.z = msg->imu.gyroscope[2];

    msg_imu.linear_acceleration.x = msg->imu.accelerometer[0];
    msg_imu.linear_acceleration.y = msg->imu.accelerometer[1];
    msg_imu.linear_acceleration.z = msg->imu.accelerometer[2];

    ROS_INFO("Publishing IMU data...");

    pub_imu.publish(msg_imu);
}

void publish_odom(const unitree_legged_msgs::HighState::ConstPtr &msg, ros::Time current_time)
{
    nav_msgs::Odometry msg_odom;

    msg_odom.header.seq = seq;
    msg_odom.header.stamp = current_time;
    msg_odom.header.frame_id = "odom";
    msg_odom.child_frame_id = "base_link";

    msg_odom.pose.pose.position.x = msg->position[0];
    msg_odom.pose.pose.position.y = msg->position[1];
    msg_odom.pose.pose.position.z = msg->position[2];

    msg_odom.pose.pose.orientation.w = msg->imu.quaternion[0];
    msg_odom.pose.pose.orientation.x = msg->imu.quaternion[1];
    msg_odom.pose.pose.orientation.y = msg->imu.quaternion[2];
    msg_odom.pose.pose.orientation.z = msg->imu.quaternion[3];

    msg_odom.twist.twist.linear.x = msg->velocity[0];
    msg_odom.twist.twist.linear.y = msg->velocity[1];
    msg_odom.twist.twist.angular.z = msg->velocity[2];
    
    ROS_INFO("Publishing odometry data...");

    pub_odom.publish(msg_odom);
}

void broadcast_tf(const unitree_legged_msgs::HighState::ConstPtr &msg, ros::Time current_time)
{
    // Store odom/imu data in global array
    position[0] = msg->position[0];
    position[1] = msg->position[1];
    position[2] = msg->position[2];

    imu[0] = msg->imu.quaternion[0];
    imu[1] = msg->imu.quaternion[1];
    imu[2] = msg->imu.quaternion[2];
    imu[3] = msg->imu.quaternion[3];
}

void highStateCallback(const unitree_legged_msgs::HighState::ConstPtr &msg)
{
    ros::Time current_time;

    current_time = ros::Time::now();
    publish_imu(msg, current_time);
    publish_odom(msg, current_time);
    broadcast_tf(msg, current_time);

    seq++;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "go1_imu");
    ros::NodeHandle nh;
    tf::TransformBroadcaster odom_broadcaster;

    state_sub = nh.subscribe("high_state", 1, highStateCallback);
    pub_imu = nh.advertise<sensor_msgs::Imu>("imu", 1);
    pub_odom = nh.advertise<nav_msgs::Odometry>("odom", 1);

    ros::Rate loop_rate(30);
    while (ros::ok())
    {
        geometry_msgs::TransformStamped odom_trans;
        ros::Time current_time = ros::Time::now();

        odom_trans.header.stamp = current_time;
        odom_trans.header.frame_id = "odom";
        odom_trans.child_frame_id = "base_link";

        odom_trans.transform.translation.x = position[0];
        odom_trans.transform.translation.y = position[1];
        odom_trans.transform.translation.z = position[2];
        odom_trans.transform.rotation.w = imu[0];
        odom_trans.transform.rotation.x = imu[1];
        odom_trans.transform.rotation.y = imu[2];
        odom_trans.transform.rotation.z = imu[3];

        odom_broadcaster.sendTransform(odom_trans);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}