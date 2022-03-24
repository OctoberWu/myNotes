#!bin/bash
echo "--- Redis Server Installation ---"
sudo apt-get install redis -y

### TODO: protection. check where the redis server is running
### if so, shutdown, if not, continue on.
echo "--- ReJSON module Installation ---"
wget https://github.com/RedisJSON/RedisJSON/archive/refs/tags/v1.0.7.tar.gz 
tar xf v1.0.7.tar.gz
cd ./RedisJSON-1.0.7
make
sudo cp ./src/rejson.so /usr/lib

echo "--- Running redis server in background ---"
# redis-server &
redis-server --loadmodule /usr/lib/rejson.so &

echo "--- Python3 modules Installation ---"
pip3 install redis rejson psycopg2
cd ~/far_flm_ws/src/far_swarm_ui/ros_mocks_ws/


exit 0