# Go1 navigation and transport

## Dependencies
The only dependency to build this project should be Docker.
You can find install instructions over on the Docker website or directly by following this [link](https://docs.docker.com/engine/install/)

## Build
On PC :
```bash
git clone git@github.com:Nitoute/PFE_Transport_Chien_Robot.git
cd PFE_Transport_Chien_Robot
git submodule update --init --recursive
xhost +local:* # If you want access to GUI
docker build -t <tag-name> .
docker run --net host \
    #-e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix/ \ # If you want acces to GUI 
    -ti go1_transport:ros1-test-build
```
On the robot:
- First, copy the <code>src</code> directory over to a catkin workspace on one of the desired Jetson nano(s) of the robot
- Connect to the previous Jetson nano and go over to the catkin workspace created for the project
- Run <code>catkin_make</code> at the root of the workspace

## Running
### Cameras
To run the camera publishers, connect to one of the robot's Jetson nanos then run :

```bash
source devel/setup.bash
export ROS_IP=192.168.123.<board IP address>
export ROS_MASTER_URI=http://192.168.123.161:11311 # Raspberry pi's address
roslaunch unitree_camera <head/body>_publishers.launch 
```

To see all available arguments, run :

`roslaunch unitree_camera <head/body>_publishers.launch --ros-args`

### IMU/Odometry
To run the IMU/odometry republisher, run the following inside the docker container:

```bash
source devel/setup.bash
roslaunch unitree_republisher imu_odom.launch
```

#### Parameters
- `keyboard_control`: bool (default: false) - Whether to launch a keyboard controller for the robot or not.
- `use_rviz`; bool (default: false) - Start visualisation with Rviz


## Useful links
Trello kanban link : https://trello.com/b/TMi6WSX4/pfe-transport-go1

Overleaf report link : https://www.overleaf.com/2373497429rbycvrqmqqsm#0de2a5
