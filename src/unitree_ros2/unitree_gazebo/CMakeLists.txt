cmake_minimum_required(VERSION 3.5)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

project(unitree_gazebo)

find_package(ament_cmake REQUIRED)

ament_export_dependencies(
    ros2_unitree_legged_msgs
)

find_package(rclcpp REQUIRED)
find_package(controller_manager REQUIRED)
# find_package(genmsg REQUIRED)
# find_package(joint_state_controller REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(std_msgs REQUIRED)
# find_package(tf REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(ros2_unitree_legged_msgs REQUIRED)
find_package(gazebo REQUIRED)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)

include_directories(
    # include
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

# # Declare a C++ library
# add_library(${PROJECT_NAME}
#     src/body.cpp 
# )

# add_dependencies(${PROJECT_NAME} unitree_legged_msgs_gencpp)

# target_link_libraries(${PROJECT_NAME}
#   ${catkin_LIBRARIES} ${EXTRA_LIBS}
# )

add_library(unitreeFootContactPlugin SHARED plugin/foot_contact_plugin.cc)
target_link_libraries(unitreeFootContactPlugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_library(unitreeDrawForcePlugin SHARED plugin/draw_force_plugin.cc)
target_link_libraries(unitreeDrawForcePlugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

ament_target_dependencies(unitreeFootContactPlugin geometry_msgs)
ament_target_dependencies(unitreeFootContactPlugin rclcpp)
ament_target_dependencies(unitreeDrawForcePlugin geometry_msgs)
ament_target_dependencies(unitreeDrawForcePlugin rclcpp)
# add_executable(unitree_external_force src/exe/external_force.cpp)
# target_link_libraries(unitree_external_force ${catkin_LIBRARIES})

# add_executable(unitree_servo src/exe/servo.cpp)
# target_link_libraries(unitree_servo ${PROJECT_NAME} ${catkin_LIBRARIES})



install(DIRECTORY
  launch worlds
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()