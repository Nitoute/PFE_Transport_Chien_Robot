# FROM tiryoh/ros-desktop-vnc:melodic
# ENV ROS_DISTRO=melodic
FROM arm64v8/ros:melodic-ros-base as builder
# FROM ros:melodic-ros-base as builder
ENV scripts=scripts
ENV ROS_MASTER_URI=http://192.168.12.1:11311
ARG WS=/opt/ros/PFE_Transport_Chien_Robot
WORKDIR /src/

# Compile and install opencv
RUN --mount=type=cache,target=/var/cache/apt \
    apt-get update \
    && apt-get install -y --no-install-recommends libgtk2.0-dev libgtk-3-dev \
    libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev libgstreamer-plugins-good1.0-dev \
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
    gstreamer1.0-tools gstreamer1.0-libav \
    gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio

ADD ./opencv ./opencv
ADD ./${scripts}/install-opencv.sh ${WS}/${scripts}/
RUN ${WS}/${scripts}/install-opencv.sh

RUN <<EOF
set -e
apt-get update && apt-get install curl software-properties-common -y
sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
add-apt-repository universe && apt-get update
EOF

# install bootstrap tools
RUN --mount=type=cache,target=/var/cache/apt \
    apt-get update \
    && apt-get install --no-install-recommends -y \
    # apt-utils \
    build-essential \
    libudev-dev\
    liblcm-dev\
    ros-${ROS_DISTRO}-controller-interface \
    ros-${ROS_DISTRO}-gazebo-ros-control \
    ros-${ROS_DISTRO}-joint-state-controller \
    ros-${ROS_DISTRO}-effort-controllers \
    ros-${ROS_DISTRO}-joint-trajectory-controller \
    ros-${ROS_DISTRO}-robot-state-publisher \
    ros-${ROS_DISTRO}-xacro \
    ros-${ROS_DISTRO}-cv-bridge \
    ros-${ROS_DISTRO}-image-transport \
    ros-${ROS_DISTRO}-rtabmap-ros \
    ros-${ROS_DISTRO}-nodelet \
    ros-${ROS_DISTRO}-tf2-ros \
    ros-${ROS_DISTRO}-tf2-geometry-msgs \
    ros-${ROS_DISTRO}-message-generation \
    ros-${ROS_DISTRO}-diagnostic-updater \
    ros-${ROS_DISTRO}-dynamic-reconfigure \
    ros-${ROS_DISTRO}-message-filters \
    ros-${ROS_DISTRO}-stereo-msgs \
    gdb valgrind openssh-client nano \
    && apt-get autoremove -y 

WORKDIR ${WS}
ADD src ./src/
ENV INSTALL_PATH=/home/unitree/custom_ws/install
RUN /bin/bash -c "source /opt/ros/${ROS_DISTRO}/setup.bash && catkin_make install -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH}"

FROM scratch AS export-stage
ENV INSTALL_PATH=/home/unitree/custom_ws/install
COPY --from=builder ${INSTALL_PATH} .
# FROM arm64v8/ros:melodic-ros-base
# ARG INSTALL_PATH=/home/unitree/custom_ws/install
# COPY --from=builder ${INSTALL_PATH} ${INSTALL_PATH}
# ENV WS=/opt/ros/PFE_Transport_Chien_Robot
# ENV ROS_MASTER_URI=http://localhost:11311

# ADD ${scripts}/setup.sh ${scripts}/setup.sh

# ADD UnitreecameraSDK ./UnitreecameraSDK