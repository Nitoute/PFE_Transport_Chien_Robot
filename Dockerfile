FROM ros:humble-ros-base

# install bootstrap tools
RUN apt-get update && apt-get install --no-install-recommends -y \
    build-essential \
    python3-rosdep \
    python3-rosinstall \
    python3-vcstools \
    && rm -rf /var/lib/apt/lists/*

# bootstrap rosdep
RUN rosdep init && \
  rosdep update --rosdistro $ROS_DISTRO && rosdep install --from-paths src --ignore-src -r -y

# install ros packages
# RUN apt-get update && apt-get install -y --no-install-recommends \
#     ros-noetic-ros-base=1.5.0-1* \
#     ros-melodic-controller-interface \
#     ros-melodic-gazebo-ros-control \
#     ros-melodic-joint-state-controller \
#     ros-melodic-effort-controllers \
#     ros-melodic-joint-trajectory-controller \
#     && rm -rf /var/lib/apt/lists/*

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