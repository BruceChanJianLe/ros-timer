#include "ros-timer/ros_timer.hpp"


namespace timer_example
{
    node::node()
    :   global_nh_(ros::NodeHandle()),
        private_nh_(ros::NodeHandle("~")),
        timer_frequency_(1.0)
    {
        // Initialize publisher
        pub_ = private_nh_.advertise<std_msgs::Int64>("counts", 1, true);

        // Initialize msg
        msg_.data = 0;

        // Initialize timer
        timer_ = global_nh_.createTimer(
            ros::Duration(1.0 / timer_frequency_),
            [this](const ros::TimerEvent & event)
            {
                this->timerCB(event);
            }
        );
    }

    node::~node()
    {
        ROS_INFO_STREAM(
            ros::this_node::getName() << " " << __func__ <<
            " stopping timer."
        );
        timer_.stop();
    }

    void node::start()
    {
        ROS_INFO_STREAM(
            ros::this_node::getName() << " " << __func__ <<
            " starting timer."
        );
        timer_.start();
    }

    void node::timerCB(const ros::TimerEvent &)
    {
        // Display node info
        ROS_INFO_STREAM(
            ros::this_node::getName() << " " << __func__ <<
            " count is " << msg_.data
        );
        pub_.publish(msg_);
        ++msg_.data;
    }
} // namespace timer_example