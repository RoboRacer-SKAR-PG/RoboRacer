#!/bin/bash

cd ${WORKSPACE_DIR}
source /opt/ros/foxy/setup.bash
source install/setup.bash
ros2 run robot_controller robot_node
