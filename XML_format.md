
事項建議：
* NavClient的寫法會依照原本的寫法(參照ppt) 不用subtree寫法。 (DRI: FARobot)
* 產生的XML縮排格式不一致，如圖。                           (DRI: S次)
* WaitAction 中帶的變量的名稱不一致 (duration, 不是value)。 (DRI: S次)
ps. 格式會依照投影片的格式。
https://farobottech-my.sharepoint.com/:p:/p/eduardo_munera/Ed45DTY0sDJAjImhwNABeYEBiYmBmF8UKQ5Iz-X6ZJfBNQ?e=7gJAxZ


### Copy the data from docker image
$docker cp web-service-demo:/root/public/ ./fms_ws/


ARPG:
* update/upgrade firmware, configuration. 
* can check whether additional infomation after the network is connected. MAC address, ssid to identify machines.
* set the ip and rest of thing, low-level stuff
* parameters
* send / retrieving files APIs. 
* modification check. Return error code to show its status. API return the error code.


Recaps:
1. auto-discovery,  
2. Event-Error Reporter.
3. update scope, system-wise(OS), or firmware-level(peripheral devices).
4. deploy way. binary or docker ways.
5. When the number goes up, how to deploy efficicently. 
6. docker registy


DDS + ROS management, 2nd dev.
1. discovery
UserCase:
1. default ssid, tool to discovery, recv device info, like MAC, model
2. device infomation from AMR
3. User Account.(System-wise)

