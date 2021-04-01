#include "ros-timer/ros_timer.hpp"
#include <string>


int main(int argc, char ** argv)
{
    ros::init(argc, argv, "ros_timer_node");

    timer_example::node node;
    
    node.start();

    ros::spin();

    return 0;
}