RabbitMQ Installation

#### Step 1: Install Erlang/OTP
1-1: Import Erlang GPG Key
```sh
sudo apt update
sudo apt install software-properties-common apt-transport-https
wget -O- https://packages.erlang-solutions.com/ubuntu/erlang_solutions.asc | sudo apt-key add -
```
1-2: Add Erlang Repository to Ubuntu 22.04|20.04|18.04
```sh
echo "deb https://packages.erlang-solutions.com/ubuntu focal contrib" | sudo tee /etc/apt/sources.list.d/erlang.list
```

1-3: Install Erlang on Ubuntu 22.04|20.04|18.04
```sh
sudo apt update
sudo apt install erlang -y
```

---
#### Step 2: Install RabbitMQ on Ubuntu 22.04|20.04|18.04
```sh
curl -s https://packagecloud.io/install/repositories/rabbitmq/rabbitmq-server/script.deb.sh | sudo bash
```

---
### Step 3: Install RabbitMQ Server Ubuntu 22.04|20.04|18.04
```sh
sudo apt update
sudo apt install rabbitmq-server -y

# after installation, to check the status
systemctl status rabbitmq-server.service

# confirm if the service is configured to start on boot using the command:
systemctl is-enabled rabbitmq-server.service 
```

---
### Step 4: Enable the RabbitMQ Management Dashboard (Optional)
```sh
sudo rabbitmq-plugins enable rabbitmq_management

# The Web service should be listening on TCP port 15672
sudo ss -tunelp | grep 15672

# If you have an active UFW firewall, open both ports 5672 and 15672:
# Access it by opening the URL http://[server IP|Hostname]:15672
sudo ufw allow proto tcp from any to any port 5672,15672

# To be able to login on the network, create an admin user like below:
sudo rabbitmqctl add_user admin StrongPassword
sudo rabbitmqctl set_user_tags admin administrator
# [IMPORTANT] set the permission
sudo rabbitmqctl set_permissions -p / admin ".*" ".*" ".*"
# restart the service
sudo systemctl stop rabbitmq-server.service               
sudo systemctl start rabbitmq-server.service
```

### [Client] Install python3 RabbitMQ package `pika` 
```sh
sudo pip3 install pika
```

--- 
### Using Docker RabbitMQ
```docker
docker pull rabbitmq:management
docker run -d -p 15672:15672 -p 5672:5672 -e RABBITMQ_NODENAME=my-rabbit --name some-rabbit rabbitmq:management
```
