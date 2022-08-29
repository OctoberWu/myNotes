系統畫面

德國林德叉車
semi-2

充電時間 40分鐘以內 110v
20V 220V 鈦酸鋰電池（鋰鐵fail 快充）

group 下來的任務，決定要不要grouping

斜坡失速狀況，台車
離地不免被台車拖著走。
情境，與台車使用的情境。


**traffic_editor** and **building_map_toolspackages** in https://github.com/osrf/traffic_editor

Traffic Schedule Database

 robot traffic monitoring and resolving conflicts or dead-locks that may arise between robots or fleets of robots that are unaware of each other's presence

* Traffic Editor
Responsive UI (laptop, pad, phone)


### Questions:
* Who are our target customers
* Priority depends on customer perspective or product perspective


### Farobot Future Plan
1. 場域需求。產品為目標 Outside In
2. Q3前機器人上市。
3. 安傑倫雲服務。得到5~10間公司需求，再做收斂。


* push_back how to deal with memory from interface
copy or reference?


if CMake doesn't find the path
https://stackoverflow.com/questions/49816206/cmake-find-package-specify-path
https://cmake.org/cmake/help/latest/command/find_package.html


official way:
```
find_package (<package> PATHS paths... NO_DEFAULT_PATH)
find_package (<package>)
```

feasible way:
```cmake
set set(SDL2_DIR /usr/local/lib/cmake/SDL2) 
find_package(SDL2 REQUIRED)
```


### 20200910 MiR250 Training 
MiR 100, 200 +-10cm 24V

* MiR 250
Speed: 2m/s
Precision: 5cm
SICK: nanotype, 48V
---
Standard（參數不能改）
Dynamic(針對場景修改參數)
Shelf Carrier(頂昇)

AP in the AMR, self-contained.

1. 播放音效
2. 切換地圖 (Redo intial pose. Align laser and map)
3. IO模組


* 地圖 > 點位 > 邏輯
給起點跟終點，自己計算路徑。可以dummy點(中繼點)，作路徑規劃。

- Features
機器人佔地面積(foot-print)。可即時修改佔地面積。

##### 監控
下了幾次命令，成功幾次。僅能在系統上看。
錯誤日誌：回報車子的狀況
系統生成 
手動生成 > 在原廠系統作錯誤追蹤。

##### 安全系統
- Features
顯示掃描即時狀況，在安全範圍最後一層。

##### 任務日誌 
- Misc.
系統>設置。設定完須重新開機

- Software Function
**2 SLAM modes**
Hector     : 100*100m 的地圖
cartograph : 掃很大的地圖

### Hardware Specification
- 電池 MiR250 
只有一顆，其他型號有兩顆。

- 校準，單位公分
作單台的精度校正。offset
板金定位 提供圖面 由客戶加工
V, L, VL +- 1cm  1度 


板金的位置，要放在機器人的前面。是用機器人的前面作的。停在物件的前方多遠？按經驗，**半個車身**才能測到VL
機械手臂，Conveyor的高精度要求場域

UR 機械手臂的對接 **ROS-I的開發需求。**
最適配的選擇，網路設定等
PLC 暫存器的設定

#### 軟體更新
0. Backup
1. Upload
2. Reload

Can't downgrade, but reload backup.

#### 所有東西跟地圖跑
1. Create Map
2. Load waypoints
3. Load task

站點。大樓 可以存10層樓地圖資訊

- Function
下載地圖，只是png
export 整包的資訊

手動。按下重新啟動後，轉一下key，開始啟動。

#### laser interference
1. In practice, the interfaces hanppens
in a narrow hallway. the interference exists.


##### 手選路線
盡可能按照路線作移動。

- Features
到特定區域時，觸發IO

- 使用邏輯
##### 程式編輯，目前有100多行，暫無行數限制。
REST API 可進行更為複雜的程式編輯
可作子任務的調用

- Error Handling
會一直繞圈圈 > 停止下放指令。
出現錯誤訊息後，到錯誤訊息，把紀錄下下來回覆原廠。


##### 
車隊的版本跟機器人的版本要一致

- Operating Procedure
第1台不勾，第2台要
Factory reset the robot before 


### 派車前要作儀表板
limit queues on AMRs at certain cirteria.


#### ROS_API 
多機任務
單個任務，派放任務給單機
async task，必須單機派放。

#### PLC and remote IO
無塵認證；安規認證
友達嚴格，國產燒掉。無塵室須重建。
電池認證、車體的認證。

自動切地圖。
站點綁地圖，當站點在任務程序中切換時，轉換成相應的地圖。




# quick test for 500 hundred messages testing 
### Test List
1. amcl goes crazy
2. mileage  
3. C++17 optional

3. When the number of task goes enomous, what will happend to the task list, overflow?
4. How many are the interfaces


#### The Number Test
- the number in task list goes up.
- Number of Completed task
- the number of AMRs abnormally.
- Queue, 
 
#### The Range(Dimension, size) Test
- The percentage of battery ( under 0, over 100)
- The mileage goes negative, or extreme large.
#### The frequency Test
- Remapping process (How to switch map efficiently)

#### Invalid BT format



Swarm Robotics 的優勢
![](/doc/HuaWeiAMR.png)
[探析華為內部移動機器人（AGV）應用現狀](https://kknews.cc/zh-tw/tech/rj2va44.html)

you are not controlling robots, but the production process workflow.
you should not take care how to control robot, but organize the production process
Pick, Pack Sorting, distributing, segregation

It doesn't matter who I am underneath, but what I do that defines me. Behavoir-oriented

Granular tracking, shipping, storing, and inventory management


### anthor writing style:
```python
    ld = LaunchDescription()

    config = os.path.join(
        get_package_share_directory('far_task_runner'),
        'config',
        'farobot_params.yaml'
    )


    node = launch_ros.actions.Node(
        package='far_task_runner',
        node_executable='far_task_runner_node',
        parameters=[config],
        output='screen',
    )

    ld.add_action(node)
    return l
```

robot mode

* Task Dispatching Logic
1. Check the robot state(IDLE, or Working[Move, Pause], Fail[Abort])
1-1. if IDLE
    Check default task_id(Yes, No)
        Yes case: Switch Task from working to complete, Do task dispatching  
        No  case: Do task dispatching,   

1-2. If Emergency (Fail Over)
    Check default task_id(Yes, No)
        Yes case: Task transfer  
        No  case: Show Warning,   

2-1. Task Dispatching (On Demand)
    New Task is available(Yes, No)
        Yes case: Task transfer  
        No  case: None,   

1. ROBOT_MODE_IDLE + No    task_id + got task_id > Wait for dispatching
1. ROBOT_MODE_IDLE + Has-a task_id + got task_id > Wait for dispatching






火鍋106-粵式豬肚雞煲鍋光復店   11:30
忻殿堂南洋叻沙鍋物 12:00  4.8 
https://nikki20100403.pixnet.net/blog/post/485891333-%E5%8F%B0%E5%8C%97%E6%9D%B1%E5%8D%80%E7%81%AB%E9%8D%8B%E6%8E%A8%E8%96%A6-%E5%BF%BB%E6%AE%BF%E5%A0%82%E5%8D%97%E6%B4%8B%E5%8F%BB%E6%B2%99%E9%8D%8B%E7%89%A9-%E5%8F%B0%E5%8C%97

https://www.mecocute.com/taipei-eat-hotpot/

