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

