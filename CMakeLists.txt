cmake_minimum_required(VERSION 3.0.2)
project(ros-timer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES ros-timer
#  CATKIN_DEPENDS dynamic_reconfigure roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(
  timer
  src/ros_timer_node.cpp
  src/ros_timer.cpp
)
target_link_libraries(
  timer
  ${catkin_LIBRARIES}
)