#!/bin/bash

cd ${WORKSPACE_DIR}
source /opt/ros/foxy/setup.bash
rosdep install -i --from-path src --rosdistro foxy -y
colcon build
source install/setup.bash
