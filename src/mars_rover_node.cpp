#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/Image.h>

class MarsRoverNode {
public:
    MarsRoverNode(ros::NodeHandle nh) : nh_(nh) {
        // Initialize ROS publishers and subscribers
        image_pub_ = nh_.advertise<sensor_msgs::Image>("/mars_rover/camera/image_raw", 1);
        speed_sub_ = nh_.subscribe("/mars_rover/max_speed", 1, &MarsRoverNode::maxSpeedCallback, this);

        // Example initialization
        max_speed_ = 1.0;
    }

    void spin() {
        // Main loop: publish data, update state, etc.
        ros::Rate rate(10); // 10 Hz
        while (ros::ok()) {
            // Example: Publish image data
            sensor_msgs::Image image_msg;
            // Fill image_msg with data from simulated camera

            image_pub_.publish(image_msg);

            ros::spinOnce();
            rate.sleep();
        }
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher image_pub_;
    ros::Subscriber speed_sub_;
    double max_speed_;

    void maxSpeedCallback(const std_msgs::Float64::ConstPtr& msg) {
        // Callback function for receiving max speed parameter
        max_speed_ = msg->data;
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "mars_rover_node");
    ros::NodeHandle nh;

    MarsRoverNode mars_rover(nh);
    mars_rover.spin();

    return 0;
}
