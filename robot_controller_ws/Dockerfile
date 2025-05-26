FROM ros:foxy

ENV DEBIAN_FRONTEND=noninteractive \
    ROS_DOMAIN_ID=0 \
    RMW_IMPLEMENTATION=rmw_cyclonedds_cpp \
    WORKSPACE_DIR=/robot_controller_ws

# Install required packages
RUN apt-get update && apt-get install -y \
    ros-foxy-desktop \
    python3-colcon-common-extensions \
    ros-foxy-rmw-cyclonedds-cpp \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update

# Copy robot controller workspace
RUN mkdir -p $WORKSPACE_DIR/src
COPY ./ $WORKSPACE_DIR

RUN chmod +x ${WORKSPACE_DIR}/run_nodes.sh
RUN chmod +x ${WORKSPACE_DIR}/build.sh
CMD ["/bin/bash", "-c", "${WORKSPACE_DIR}/build.sh && ${WORKSPACE_DIR}/run_nodes.sh"]
