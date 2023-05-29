

### docker
```sh
docker run -v /var/run/docker.sock:/var/run/docker.sock -it alpine sh
```

### docker-compose up for only certain containers
```sh
# template: 
docker-compose up -d <service_container>
# ex. 
docker-compose up -d client
```
### footnote: 如果跑單個contain 沒有加 `-d`, ports不會被綁定到本機。
```sh 
# 沒有bind port的版本
docker-compose run <service_container>
# bind port的版本參考上面。
```
```sh
# template: 
docker-compose -f <docker-compose-yml-filename> up -d <service-name> 
# ex. 
docker-compose -f docker-compose.dev.yml up -d app
```

### Get the IP address of docker container
```
docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' swarm_core_service
```


### The images got dependent child images
```sh
# Use the python3 script(docker_descendant.py) to detect
$python3 docker_descendants.py <image_id> 
```



### Remove all docker containers and images
```sh
$docker rm -vf $(docker ps -a -q) && docker rmi -f $(docker images -a -q)

# combination od the following two
$docker rm -vf $(docker ps -a -q) 
$docker rmi -f $(docker images -a -q) 
```


### Check docker container status
```sh
# 1. list all docker stats
$docker stats
# 2. list all containers 
$docker ps -a
```

### Enter executing container
```sh
$docker exec -it web-service-demo bash
```

### Copy content from docker to host 
```sh
$docker cp api-service-demo:/root/ ./fms_api
```

#### Summary 
1. Retain all the modifications in docker image 
Do commit. but it's not recommanded
2. Save the image file
docker save -o image.tar techday_sim:v1
3. Load the image
docker load -i image.tar
4. push the related archive into the corresponding folders
5. launch the image

---

#### Change the Authentication of a folder
```sh
$sudo chown ros:ros .ros
```
---

### docker workflow and lifecycle 
1. build docker image
2. run in container
3. if the status of container is exited
4. start the container again.

#### Docker workflow
刪除 Docker Image
Docker 提供了 rmi 參數, 可以用作刪除 images, 但在執行前, 我們需要知道 image id, 先用以下指令找出 image id:

# docker images
##### 找到要刪除的 image 的 image id 後, 便可以執行以下指令刪除:
```sh
$docker rmi image_id
```
##### 刪除 Docker Containers
要刪除 containers, 跟上面的做法差不多, 只要將參數換成 rm, 但在執行前, 要先找出 container id:
```sh
$docker ps -a
```
##### 找到了要刪除的 container 的 container id 後, 如果 container 正在執行, 要先停止才可以刪除, 以下是將 container 停止及刪除的指令:
```sh
$docker stop container_id
$docker rm container_id
```

###### 如果想一次過將所有 container 停止及刪除, 執行以下指令:
```sh
$docker stop $(docker ps -a -q)
$docker rm $(docker ps -a -q)
```

---

### Running GUI in Docker
TBD

* The most intuitive way is to connect **Xclient in docker container** to **host Xserver**.
* 2 steps:
* 1. Allow the host to be connected. 
```
xhost +local:
```
* share /tmp/.X11-unix to the docker container
```sh
$docker run -it --rm -v /tmp/.X11-unix:/tmp/.X11-unix ${docker_image}
```

* 当然，你也可以在放开权限时指定容器主机名/或者在运行容器时指定与主机相同的名称，这样会安全一些，只是步骤上会麻烦一点
```sh
$xhost +local:$(docker inspect --format='{{ .Config.Hostname }}' $containerId)
$docker start $containerId
# or 
$docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --hostname=$HOSTNAME -v $HOME/.Xauthority:/root/.Xauthority -it --rm ${docker_image}
```

#### What is **/tmp/.X11-unix** ?
- X11 server need a way to interact with X11 client. On Internet, it's by TCP/IP socket. On host, it's by Unix-domain socket.

- Unix-domain sockert is similar to TCP/IP socket, and it just pint to a document directory without transmitting through NIC(Network Interface Controller). It would be safer, faster.

**/tmp/.X11-unix** is for restoring **Unix-domain Socket**

一般来说 /tmp/.X11-unix 下面只会有一个 Unix-domain Socket(因为一般只有一个Xserver在运行)，但若系统同时运行多个Xserver，也可能会有多个Unix Domain Socket出现的情况。

```sh
ls -l /tmp/.X11-unix
总用量 0
srwxrwxrwx 1 lujun9972 lujun9972 0 4月  24 09:18 X0
```
注意到 X0 前面的 s ，说明它是一个socket文件。

我们可以使用 lsof -U 来查看有那些进程在使用这个 Unix-domain Socket

```sh
$lsof -U /tmp/.X11-unix/X0 |cut -f1 -d " " |uniq
COMMAND
systemd
xinit
Xorg
...
```

* root source [Using GUI's with Docker](http://wiki.ros.org/docker/Tutorials/GUI)
* [docker容器中跑GUI的最简单方法](http://blog.lujun9972.win/blog/2018/04/24/docker%E5%AE%B9%E5%99%A8%E4%B8%AD%E8%B7%91gui%E7%9A%84%E6%9C%80%E7%AE%80%E5%8D%95%E6%96%B9%E6%B3%95/index.html)

---

### Docker 
**IDs Only**
```sh
#quiet
$docker image -q
```
rmi: remove image <image_id> <image_id>
rm:  remove image <container_id> <container_id>


1. Stop and Remove Docker **Images**

**List**
```sh
$docker images -a | grep "pattern"
``` 

**Remove**
```sh
$docker rmi <image_id> <image_id>
$docker images -a | grep "pattern" | awk '{print $3}' | xargs docker rmi 
``` 

1. Stop and Remove Docker **Containers** 
**List**
```sh
$docker ps -a
``` 

**Stop**
```sh
#stop all containers
$docker stop $(docker ps -a -q)
```

**Remove**
```sh
#stop first
$docker stop $(docker ps -a -q)
$docker rm `ID or Name` `ID or Name` 
$docker rm $(docker ps -a -q) 
``` 

*Examples*
```sh
$docker start i ros_techday
$docker images -a
$docker stop fe69354c3ff5
$docker stop a8bf72287228 a8bf72287228
$docker stop  $(docker ps -a -q)
$docker image rm fe69354c3ff5 fe69354c3ff5
$docker rmi fe693 fe693
$docker rmi fe69354c3ff5
$docker ps -a
$docker rm fe69354c3ff5
$docker rm a8bf72287228 a8bf72287228
```

---

#### docker
```sh
# run container 
$docker container start <container_id> 
$docker container start 20377be9dc45

# attach container 
$docker attach <container_id> 
$docker attach 20377be9dc45
```

