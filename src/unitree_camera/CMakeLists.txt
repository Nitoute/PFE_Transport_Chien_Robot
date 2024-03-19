cmake_minimum_required(VERSION 3.0.2)
project(unitree_camera)

set(PUB_NAME "camera_publisher")
set(DEPTH_NODE "depth_publisher")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -g -O0")
## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  cv_bridge
  pcl_ros
  UnitreeCameraSDK
  image_transport
  catkin
)

## System dependencies are found with CMake's conventions
find_package(OpenCV 4 REQUIRED)
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIR})
    message(STATUS "OpenCV ${OpenCV_VERSION} FOUND")
    message(STATUS ${OpenCV_INCLUDE_DIR})
    message(STATUS ${OpenCV_LIBS})
else()
    message(FATAL_ERROR "OpenCV Library Not Found")
endif()

catkin_package(
  INCLUDE_DIRS include
  # LIBRARIES unitree_camera
  CATKIN_DEPENDS  roscpp std_msgs sensor_msgs cv_bridge pcl_ros image_transport
#  DEPENDS system_lib
)

set(SDKLIBS unitree_camera tstc_V4L2_xu_camera udev systemlog ${OpenCV_LIBS})

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
link_directories(${PROJECT_SOURCE_DIR}/lib/amd64/)
else()
link_directories(${PROJECT_SOURCE_DIR}/lib/arm64/)
endif()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include/
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)

## Specify libraries to link a library or executable target against
add_executable(${PUB_NAME} src/${PUB_NAME}.cpp src/${DEPTH_NODE}.cpp)
add_dependencies(${PUB_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PUB_NAME}
  ${catkin_LIBRARIES}
  ${SDKLIBS}
)

# add_executable(${DEPTH_NODE} src/${DEPTH_NODE}.cpp)
# add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
# target_link_libraries(${DEPTH_NODE}
#   ${catkin_LIBRARIES}
#   UnitreeCameraSDK
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
install(TARGETS ${PUB_NAME}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)
install(DIRECTORY config/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config)