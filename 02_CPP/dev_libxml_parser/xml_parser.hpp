#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "far_task_msgs/msg/task_command.hpp"
#include "far_task_msgs/msg/task_content.hpp"
#include "far_task_msgs/msg/task_state.hpp"
#include "far_task_msgs/msg/task_summary.hpp"

#include "far_fleet_msgs/msg/fleet_state.hpp"
#include "far_fleet_msgs/msg/robot_mode.hpp"
#include "far_fleet_msgs/msg/robot_state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

using TaskCommand = far_task_msgs::msg::TaskCommand;
using TaskSummary = far_task_msgs::msg::TaskSummary;

using RobotState = far_fleet_msgs::msg::RobotState;
using RobotMode = far_fleet_msgs::msg::RobotMode;

// typedef std::pair<std::string, BT::Tree> bt_task;
typedef std::pair<std::string, std::string> bt_task;

