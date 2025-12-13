#include <gtest/gtest.h>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// Test fixture for MyFirstNode
class TestMyFirstNode : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize ROS 2 if not already initialized
        if (!rclcpp::ok()) {
            rclcpp::init(0, nullptr);
        }
    }

    void TearDown() override {
        // Cleanup if needed
    }
};

// Test that the node can be created
TEST_F(TestMyFirstNode, NodeCreation) {
    // This test verifies that a ROS 2 node can be created
    auto node = std::make_shared<rclcpp::Node>("test_node");
    EXPECT_NE(node, nullptr);
    EXPECT_STREQ(node->get_name(), "test_node");
}

// Test that publisher can be created
TEST_F(TestMyFirstNode, PublisherCreation) {
    auto node = std::make_shared<rclcpp::Node>("test_publisher_node");
    auto publisher = node->create_publisher<std_msgs::msg::String>("test_topic", 10);
    EXPECT_NE(publisher, nullptr);
}

// Test string message
TEST_F(TestMyFirstNode, StringMessage) {
    auto message = std_msgs::msg::String();
    message.data = "Hello, ROS2 World!";
    EXPECT_EQ(message.data, "Hello, ROS2 World!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
