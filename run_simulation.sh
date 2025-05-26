#!/bin/bash

if [ -z "$SUDO_USER" ]; then
  echo "Run script with sudo!"
  exit
fi

xhost +local:docker
docker-compose up