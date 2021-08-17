1. netstat -tpnl 。觀察哪些port已經使用了。
2. sudo nmap -sP 10.42.0.1/24 。 搜尋在改往域中使用的設備及其名稱。
3. sudo apt install terminator

4. nvm list
5. nvm alias default v12.18.3
6. nvm install 12.18.3

6. ros2 service call /fb_2/map_server/map /nav_msg/srv/GetMap

7. ros2 type /fb_0/map_server/map 

8. daemond, systemd
9. docker images


1. trigger start 的按鈕。 設計trigger 的topics及相應的內容。

任務啟動的運行


1. 當任務在robot端，被卡死時。該採取什麼對策。重新啟動？
2. FLM queue住任務時，FLM無法移除任務，該採取什麼對策？ 重啟
robot state的task_id在完成任務後，並沒有更新。

Nav2 會回傳什麼資料，顯示一直無法到位。
FLM 如何判斷已經與AMR斷線。

3. Task Runner在不對的XML格式下會自動crash退出。

4. 將topics收斂

5. 將topics全部收在一個topics
trigger_event, interrupt_event

far_ui_ws, simple_ui should be remove localhost