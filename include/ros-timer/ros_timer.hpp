#ifndef ROS_TIMER_H_
#define ROS_TIMER_H_

#include <ros/ros.h>
#include <std_msgs/Int64.h>

#include <string>
#include <memory>


namespace timer_example
{
    class node
    {
    private:
        ros::NodeHandle global_nh_;
        ros::NodeHandle private_nh_;

        ros::Publisher pub_;

        ros::Timer timer_;

        std_msgs::Int64 msg_;

        double timer_frequency_;

        void timerCB(const ros::TimerEvent &);
    public:
        node();
        ~node();

        void start();
    };
} // namespace timer_example


#endif