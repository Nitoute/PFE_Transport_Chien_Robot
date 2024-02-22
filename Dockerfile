FROM tiryoh/ros-desktop-vnc:melodic
ENV ROS_DISTRO=melodic
# FROM ros:melodic-ros-base
ENV scripts=scripts
ENV ROS_MASTER_URI http://192.168.12.1:11311
WORKDIR /home/ubuntu
ADD ./opencv ./opencv
ADD ./lcm-1.4.0.zip PFE_Transport_Chien_Robot/
ADD ./${scripts} PFE_Transport_Chien_Robot/${scripts}
RUN PFE_Transport_Chien_Robot/${scripts}/install-lcm.sh & PFE_Transport_Chien_Robot/${scripts}/install-opencv.sh

RUN <<EOF
set -e
apt-get update && apt-get install curl software-properties-common -y
sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
add-apt-repository universe && apt-get update
EOF

# bootstrap rosdep
RUN rosdep update --rosdistro ${ROS_DISTRO}
# install bootstrap tools
RUN --mount=type=cache,target=/var/cache/apt \
    apt-get update && \
    apt-get -y install libgtk2.0-dev libgtk-3-dev \
    libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev libgstreamer-plugins-good1.0-dev \
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
    gstreamer1.0-tools gstreamer1.0-libav \
    gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio \
    # apt-get install -y \
    build-essential \
    python3-catkin-pkg \
    python3-rosdep \
    python3-rosinstall \
    python3-vcstools &&\
    apt-get install -y \
    ros-${ROS_DISTRO}-controller-interface \
    ros-${ROS_DISTRO}-gazebo-ros-control \
    ros-${ROS_DISTRO}-joint-state-controller \
    ros-${ROS_DISTRO}-effort-controllers \
    ros-${ROS_DISTRO}-joint-trajectory-controller \
    ros-${ROS_DISTRO}-robot-state-publisher \
    ros-${ROS_DISTRO}-xacro \
    ros-${ROS_DISTRO}-cv-bridge \
    ros-${ROS_DISTRO}-image-transport\
    ros-${ROS_DISTRO}-rtabmap-ros && \
    apt-get autoremove -y

WORKDIR /home/ubuntu/PFE_Transport_Chien_Robot
ADD src ./src
ADD test.py .
# RUN /bin/bash ${scripts}/build-project.sh