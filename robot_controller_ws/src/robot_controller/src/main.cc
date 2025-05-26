#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"

class LaserScanSubscriber : public rclcpp::Node {
public:
    LaserScanSubscriber() : Node("laser_scan_subscriber")
    {
        lastError = 0;
        subscription = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10,
            std::bind(&LaserScanSubscriber::laser_callback, this, std::placeholders::_1));

        publisher = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("/drive", 10);
    }

private:
    void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        
        float angle1 = 80.0 * M_PI / 180.0;
        float angle2 = -80.0 * M_PI / 180.0;
        float dist1 = -1.0;
        float dist2 = -1.0;


        float alpha = msg->angle_min;
        for (unsigned int i = 0; i < msg->ranges.size(); i++) {
            if (alpha > angle2 && dist2 == -1.0) {
                dist2 = msg->ranges[i]; 
            }

            if (alpha > angle1 && dist1 == -1.0) {
                dist1 = msg->ranges[i]; 
            }

            alpha += msg->angle_increment;
        }

        auto message = ackermann_msgs::msg::AckermannDriveStamped();
        float error = abs(dist1-dist2);
        message.drive.steering_angle = error*2;
        
        if (lastError != 0) {
            // message.drive.steering_angle += error * (error/lastError);
        }

        if (dist1 < dist2) {
            message.drive.steering_angle *= -1;
        }

        message.drive.speed = 2;
        publisher->publish(message);

        RCLCPP_INFO(this->get_logger(), "Publishing: speed = %.2f, angle = %.2f",
        message.drive.speed, message.drive.steering_angle);
        lastError = error;
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription;
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher;
    float lastError;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaserScanSubscriber>());
    rclcpp::shutdown();
    return 0;
}
