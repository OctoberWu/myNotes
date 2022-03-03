
### rosbridge_suite 
* resolve the rosbridge fragment size limit. 
* default max_message_size = 10000000 (bytes)
* to extend, conduct the command with the flag like below:
```sh
ros2 run rosbridge_server rosbridge_websocket --ros-args -p max_message_size:=50000000

pm2 start ./rosbridge_websocket --interpreter=python3 -- --ros-args -p port:=9091

pm2 start ./rosbridge_websocket --interpreter=python3 --max-memory-restart 1500M -- --ros-args -p max_message_size:=1000000000
```

ref link:
1. https://github.com/RobotWebTools/rosbridge_suite/issues/41
2. https://github.com/RobotWebTools/rosbridge_suite/issues/699


chrome://inspect/#workers
check `Shared workers` > far_ros_worker.js 

---

NOTE:
* 使用 Websocket 建立連線後，須留意connection的狀態，避免 data frame的塞車(Data Frame Congestion)。
* 如果使用Node.JS，則留意setInterval 是否在 'connection' 的callback中。避免建立連線時，皆產生一個timer作setInterval()