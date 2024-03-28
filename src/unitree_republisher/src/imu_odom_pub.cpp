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

float quaternion[4] = {0, 0, 0, 1};
float gyroscope[3] = {0};
float accelerometer[3] = {0};
float velocity[3] = {0};
float position[3] = {0};
long seq = 0;

void publish_imu(ros::Time current_time)
{
    sensor_msgs::Imu msg_imu;

    msg_imu.header.seq = seq;
    msg_imu.header.stamp = current_time;
    msg_imu.header.frame_id = "imu_link";

    msg_imu.orientation.w = quaternion[0];
    msg_imu.orientation.x = quaternion[1];
    msg_imu.orientation.y = quaternion[2];
    msg_imu.orientation.z = quaternion[3];

    msg_imu.angular_velocity.x = gyroscope[0];
    msg_imu.angular_velocity.y = gyroscope[1];
    msg_imu.angular_velocity.z = gyroscope[2];

    msg_imu.linear_acceleration.x = accelerometer[0];
    msg_imu.linear_acceleration.y = accelerometer[1];
    msg_imu.linear_acceleration.z = accelerometer[2];

    ROS_INFO("Publishing IMU data...");

    pub_imu.publish(msg_imu);
}

void publish_odom(ros::Time current_time)
{
    nav_msgs::Odometry msg_odom;

    msg_odom.header.seq = seq;
    msg_odom.header.stamp = current_time;
    msg_odom.header.frame_id = "odom";
    msg_odom.child_frame_id = "trunk";

    msg_odom.pose.pose.position.x = position[0];
    msg_odom.pose.pose.position.y = position[1];
    msg_odom.pose.pose.position.z = position[2];

    msg_odom.pose.pose.orientation.w = quaternion[0];
    msg_odom.pose.pose.orientation.x = quaternion[1];
    msg_odom.pose.pose.orientation.y = quaternion[2];
    msg_odom.pose.pose.orientation.z = quaternion[3];

    msg_odom.twist.twist.linear.x = velocity[0];
    msg_odom.twist.twist.linear.y = velocity[1];
    msg_odom.twist.twist.angular.z = velocity[2];

    pub_odom.publish(msg_odom);
}

void broadcast_tf(tf::TransformBroadcaster odom_broadcaster, ros::Time current_time)
{
    geometry_msgs::TransformStamped odom_trans;

    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "trunk";

    odom_trans.transform.translation.x = position[0];
    odom_trans.transform.translation.y = position[1];
    odom_trans.transform.translation.z = position[2];
    odom_trans.transform.rotation.w = quaternion[0];
    odom_trans.transform.rotation.x = quaternion[1];
    odom_trans.transform.rotation.y = quaternion[2];
    odom_trans.transform.rotation.z = quaternion[3];

    odom_broadcaster.sendTransform(odom_trans);

}

void highStateCallback(const unitree_legged_msgs::HighState::ConstPtr &msg)
{
    gyroscope[0] = msg->imu.gyroscope[0];
    gyroscope[1] = msg->imu.gyroscope[1];
    gyroscope[2] = msg->imu.gyroscope[2];

    velocity[0]= msg->velocity[0];
    velocity[1]= msg->velocity[1];
    velocity[2]= msg->velocity[2];

    accelerometer[0] = msg->imu.accelerometer[0];
    accelerometer[1] = msg->imu.accelerometer[1];
    accelerometer[2] = msg->imu.accelerometer[2];

    position[0] = msg->position[0];
    position[1] = msg->position[1];
    position[2] = msg->position[2];

    quaternion[0] = msg->imu.quaternion[0];
    quaternion[1] = msg->imu.quaternion[1];
    quaternion[2] = msg->imu.quaternion[2];
    quaternion[3] = msg->imu.quaternion[3];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "go1_imu");
    int freq;
    ros::NodeHandle nh;
    tf::TransformBroadcaster odom_broadcaster;

    nh.param<int>("frequency", freq, 25);

    state_sub = nh.subscribe("high_state", 1, highStateCallback);
    pub_imu = nh.advertise<sensor_msgs::Imu>("imu", 1);
    pub_odom = nh.advertise<nav_msgs::Odometry>("odom", 1);

    ros::Rate loop_rate(freq);
    while (ros::ok())
    {
        ros::Time current_time = ros::Time::now();

        publish_imu(current_time);
        publish_odom(current_time);
        broadcast_tf(odom_broadcaster, current_time);

        ROS_INFO("Publishing odometry data...");

        ros::spinOnce();
        loop_rate.sleep();

        seq++;
    }

    return 0;
}