# RoboRacer developed by SKAR at PG

---

Tested on:

- Ubuntu 20.04.6 LTS 64-bit
- Ubuntu 22.04.5 LTS 64-bit
- Ubuntu 24.04.2 LTS 64-bit

## Quick start

- clone this repository
- change directory to folder with cloned repository
- run

```bash
chmod +x ./run_simulation.sh
git submodule init
git submodule update
```

- start simulation with

```bash
sudo ./run_simulation.sh
```

## Overview

- `robot_controller_ws/` directory
  - [colcon workspace](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html) for all ROS2 foxy nodes
  - [build.sh](./robot_controller_ws/build.sh) is a script used to build nodes, at each startup of docker container
  - [run_nodes.sh](./robot_controller_ws/run_nodes.sh) is a script used to start nodes at container startup

- `simulation/` directory
  - directory for all simulation related code, especially [f1tenth_gym_ros](https://github.com/RoboRacer-SKAR-PG/f1tenth_gym_ros.git)

`run_simulation.sh` script will cause to copy [/robot_controller_ws/src/](./robot_controller_ws/src/) directory each time it is called, and all ros nodes will build at container startup, as specified in [build.sh](./robot_controller_ws/build.sh)

**Note**
To apply changes made in [run_nodes.sh](./robot_controller_ws/run_nodes.sh) or [build.sh](./robot_controller_ws/build.sh), you must run:

```bash
sudo docker-compose down --rmi all
```

Which will rebuild containers with new scripts.
