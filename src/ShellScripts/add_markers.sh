#!/bin/bash
ABS_SCRIPT_PATH=$PWD/$(dirname "$0")
echo "$ABS_SCRIPT_PATH"
ABS_DEVEL_PATH=$ABS_SCRIPT_PATH/../../devel
echo "$ABS_DEVEL_PATH"
ABS_SRC_PATH=$ABS_SCRIPT_PATH/../../src
echo "$ABS_SRC_PATH"
xterm  -e  " source $ABS_DEVEL_PATH/setup.bash ; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$ABS_SRC_PATH/World/MyWorld.world " &
sleep 5
xterm  -e  " source $ABS_DEVEL_PATH/setup.bash ; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$ABS_SRC_PATH/World/myMap8.yaml" & 
sleep 2
xterm  -e  " source $ABS_DEVEL_PATH/setup.bash ; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 2
xterm  -e  " source $ABS_DEVEL_PATH/setup.bash ; rosrun add_markers add_markers_node"
sleep 2
