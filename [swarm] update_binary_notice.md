keywords: farobot_installation

---
### Steps to update swarm binaries install
1. Download the lastest binary files
2. Back-up / Remove the original install folders
		- "farobot_dev_env/docker-services/repository_service/far_deb/"
3. Run the install binary script
```sh
cd ~/farobot_dev_env/scripts
./install_binary.sh [<remote ip>|local] [<version>] [all|amr|flm|artifact]
```
4. Run hack script 
```sh 
cd ~/farobot_dev_env/license
./open_backdoor.sh
```
5. Modify runtime config., and switch AMRs to simulation settings.
```sh
## Directory
cd ~/farobot_dev_env/data/far_fleet_data/fb_0_data/robot_params/runtime_conf.json
cd ~/farobot_dev_env/data/far_fleet_data/fb_1_data/robot_params/runtime_conf.json

## --- Configuration ---
#Docking.min_angular_velocity: 0.01
#Docking.min_velocity: 0.01
#PurePursuit.real_robot_translation_limitaion: 0.01
#PurePursuit.real_robot_rotation_limitaion: 0.01
#Rotate.min_angular_speed: 0.01
```
6. Enable inital pose on UI Configuration Page.
7. Dispatch the task.