# RoboRacer developed by SKAR at PG

---

## Quick start

- clone this repository
- change directory to folder with cloned repository
- run

```bash
chmod +x run_simulation.sh
```

- start simulation with

```bash
sudo run_simulation.sh
```

## Overview

- `robot_controller_ws/` directory
  - [colcon workspace](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html) for all ROS2 foxy nodes
  - [build.sh](./robot_controller_ws/build.sh) is a script used to build nodes, at each startup of docker container
  - [run_nodes.sh](./robot_controller_ws/run_nodes.sh) is a script used to start nodes at container startup

- `simulation/` directory
  - directory for all simulation related code, especialy [f1tenth_gym_ros](https://github.com/RoboRacer-SKAR-PG/f1tenth_gym_ros.git)

`run_simulation.sh` script will cauze to copy [/robot_controller_ws/src/](./robot_controller_ws/src/) direcotry each time it is called, and all ros nodes will build at container startup, as specified in [build.sh](./robot_controller_ws/build.sh)

**Note**
To apply changes made in run_nodes.sh or build.sh, you must run:

```bash
sudo docker-compose up --rmi all
```

Which will rebuild containers with new scripts.
