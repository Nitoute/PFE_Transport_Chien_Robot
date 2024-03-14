cmake_minimum_required(VERSION 3.0.2)
project(unitree_republisher)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  tf
  unitree_legged_msgs
  unitree_legged_sdk
  unitree_legged_real
  nav_msgs
  sensor_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
  # LIBRARIES unitree_republisher
  CATKIN_DEPENDS tf unitree_legged_msgs unitree_legged_real nav_msgs sensor_msgs unitree_legged_sdk
#  DEPENDS system_lib
)

###########
## Build ##
###########
set(EXTRA_LIBS -pthread)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/unitree_republisher.cpp
# )

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(imu_odom_pub src/imu_odom_pub.cpp)
target_link_libraries(imu_odom_pub ${catkin_LIBRARIES} ${EXTRA_LIBS})

# Mark executables for installation
# See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
install(TARGETS imu_odom_pub
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )