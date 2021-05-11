# ROS Timer

This repository demonstrates the usage of ROS Timer.

Do note that `ros::spin()` is important to block the node from exiting and executing the timer callback.

## Running Error

This happens when you want to use ROS timer and ROS dynamic reconfigure together in the same node. Basically, the ROS timer will not run at all. In this case, you should declare the ROS dynamic reconfigure after the ROS Timer. More detail of the issue can be found [here](https://answers.ros.org/question/364115/rostimer-wont-start-if-initialized-before-dynamic-reconfigure-server/) and [here](https://github.com/ros/ros_comm/issues/2085).

## Reference

- https://answers.ros.org/question/199727/how-to-use-timer/  
- http://wiki.ros.org/roscpp/Overview/Timers  
