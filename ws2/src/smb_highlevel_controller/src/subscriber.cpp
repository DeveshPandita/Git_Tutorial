#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/String.h>
void chatterCallback(const sensor_msgs::LaserScan& msg)
{
    // std::cout<<msg.data<<std::endl;
    // ROS_INFO("I heard: [%s]", msg.data.c_str());
    // std::cout<<msg.range_min<<std::endl;
    std::cout<<"hello"<<std::endl;
    ROS_INFO_STREAM("Read topic: " << msg.range_min);
}
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nodeHandle;
    float queue_size;
    std::string topic_name = nodeHandle.param<std::string>("topic_name","Hello");
    nodeHandle.getParam("/queue_size",queue_size);
    nodeHandle.getParam("/topic_name",topic_name);
    ros::Subscriber subscriber =
    nodeHandle.subscribe(topic_name,1,chatterCallback);
    ros::spin();
    return 0;

    
}