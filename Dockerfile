FROM tiryoh/ros-desktop-vnc:melodic
WORKDIR /home/ubuntu
ADD . PFE_Transport_Chien_Robot
WORKDIR /home/ubuntu/PFE_Transport_Chien_Robot
# install bootstrap tools
RUN add-apt-repository universe && apt-get update && apt-get install -y \
    build-essential \
    python3-catkin-pkg \
    python3-rosdep \
    python3-rosinstall \
    python3-vcstools \
    && scripts/setup-ros-repo.sh

# bootstrap rosdep
RUN rosdep update --rosdistro melodic

# install ros packages
RUN apt-get update && apt-get install -y \
    ros-melodic-controller-interface \
    ros-melodic-gazebo-ros-control \
    ros-melodic-joint-state-controller \
    ros-melodic-effort-controllers \
    ros-melodic-joint-trajectory-controller \
    ros-melodic-rtabmap-ros* \
    && rm -rf /var/lib/apt/lists/*

# FROM ros:humble
# RUN apt-get update && apt-get install -y \
#         ros-${ROS_DISTRO}-nav2-msgs \
#         ros-${ROS_DISTRO}-navigation2 \
#         ros-${ROS_DISTRO}-nav2-bringup \
#         ros-${ROS_DISTRO}-nav2-msgs \
#         ros-${ROS_DISTRO}-controller-manager \
#         ros-${ROS_DISTRO}-joint-state-publisher \
#         ros-${ROS_DISTRO}-joint-state-publisher-gui && \
    # rm -rf /var/lib/apt/lists/*
# ENV scripts=./scripts
# WORKDIR /home/ubuntu
# COPY . ./go1_transport
# WORKDIR /home/ubuntu/go1_transport
# RUN ${scripts}/install-lcm.sh && ${scripts}/install-opencv.sh && ${scripts}/setup-ros-repo.sh && ${scripts}/install-ros-packages.sh
# RUN source /opt/ros/humble/setup.bash