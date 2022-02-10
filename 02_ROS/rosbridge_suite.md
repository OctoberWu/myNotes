
### rosbridge_suite 
* resolve the rosbridge fragment size limit. 
* default max_message_size = 10000000 (bytes)
* to extend, conduct the command with the flag like below:
```sh
ros2 run rosbridge_server rosbridge_websocket --ros-args -p max_message_size:=50000000
```

ref link:
1. https://github.com/RobotWebTools/rosbridge_suite/issues/41
2. https://github.com/RobotWebTools/rosbridge_suite/issues/699
3. 