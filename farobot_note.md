### NavGraph load/save procedure:
### WmsCell load/save procedure:


### TODO
[] core firmware update > agent firmware update
[v] thumbnail  
[] use lodash to refactor
[v] green line disappear
[]  add timeout
[v] role editor, update modified data. fix bt block generation with undefined intial values
[] sequence diagram
 

getBtBlock() > updateUserEditVal()

payload
actuator
behavior
perception
behaviors

review flow task create procedure

[o] remove map and remove graph and cells
[] Error NOT copy and overwrite the demoui sucessfully.
[v] remove role from role editor
[v] remove map yaml file and png file

[o] convert role capability to yaml in right format
[v] switch fb_0 to fb_1 in SLAM procedure

[] append id on the agents on live-map view
[] * generate corresponding thumbnail for maps in fleet configuration

[] RMT cannot found. show hint messages on UI (change the docker-compose)
[] map image zoom in-out. scroll to zoom-in/out, drag to pan.
[] save map image to back-end file
[v] empty behavior block, while switching to role editor.

[v] one AMR to only one fleet

[] back to previous movement(回上一步)
[] WMS cell label name can't not be repeated.
[] eraser the the square to hint the stroke width.
[] range 0~360 to -180~180
[] add service call apply_configuration Empty
[] docker-compose run build_flm remove far_demo_ui in install folder

[] map dimension. could ajust or not.

8/24 Bug Fix
[o] Routing path (green line) should be removed when moving finished in live map page.

8/23 Bug Fix
[] Artifact management and behavior setting
[o] Robot icon sometimes dsappear in live map page
[v] The position of joystick will be shifted when the map is not ready.
[v] Cell id should be closer to the cell
[o] send the service call to trigger nodes to reload files
[] agent firmware on fleet page.
[] core firmware upgrade on setting page 
[] progress bar, block screen. firmware update.
[] swarm core firmware update



### Set auto-reboot while running

$cd /etc/systemd/system/*.service
$sudo systemctl start/restart/stop/enable/disable *.service

enable / disable

User: have to be root

watch -n 1 sudo systemctl status far_flm.service 


1. 機器人狀態，與UI上狀態顯示圖示的對應。
2. 機器人關掉，需要有對應的UI行為。

Open VINS-fus
HKUST
sensor fusion for odometry.
ISO 3691-4:2020 for FLM

large scale SLAM, what's its limit?
QR codee for locolization.
High accuracy, reflector. recommended not QR code
odom frame should be a better option.
not base-link frame.


### MiR robot

#### Wifi
ssid: MiR204603006
password: mirex4you

##### login 
id: distributor
pw: distributor
