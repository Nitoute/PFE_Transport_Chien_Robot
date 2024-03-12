FROM ros:humble-ros-base

SHELL ["/bin/bash", "-o", "pipefail", "-o", "errexit", "-c"]

ENV scripts=scripts
ENV ROS_MASTER_URI=http://192.168.12.1:11311
ARG WS=/opt/ros/PFE_Transport_Chien_Robot
WORKDIR /src/
ADD ./opencv ./opencv
ADD ./${scripts}/install-opencv.sh ${WS}/${scripts}/
RUN ${WS}/${scripts}/install-opencv.sh

# install bootstrap tools
RUN --mount=type=cache,target=/var/cache/apt \
    apt-get update && apt-get install --no-install-recommends -y \
    build-essential \
    python3-rosdep \
    python3-rosinstall \
    python3-vcstools \
    libgtk-3-dev\
    libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev libgstreamer-plugins-good1.0-dev\
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly\
    gstreamer1.0-tools gstreamer1.0-libav\
    gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
    # && rm -rf /var/lib/apt/lists/*

RUN rosdep update --rosdistro $ROS_DISTRO\
    && rosdep install --from-paths src --ignore-src -r -y

WORKDIR ${WS}
ADD src ./src/
ENV INSTALL_PATH=/home/unitree/custom_ws/install
RUN /source /opt/ros/${ROS_DISTRO}/setup.bash && colcon build -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH}

ENV WS=/opt/ros/PFE_Transport_Chien_Robot

RUN sed --in-place --expression \
      '$isource "${WS}/install/setup.bash"' \
      /ros_entrypoint.sh