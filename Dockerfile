FROM tiryoh/ros2-desktop-vnc:humble
ENV scripts=./scripts
WORKDIR /home/ubuntu
COPY . ./go1_transport
WORKDIR /home/ubuntu/go1_transport
RUN ${scripts}/install-lcm.sh && ${scripts}/install-opencv.sh && ${scripts}/setup-ros-repo.sh && ${scripts}/install-ros-packages.sh
RUN source /opt/ros/humble/setup.bash