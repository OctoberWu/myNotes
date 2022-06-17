keywords: docker-api,curl, http-reqeust

---
### Send Http request to /var/run/docker.sock

#### Equivalents of docker cli commands

* `docker images`
```sh
curl --unix-socket /var/run/docker.sock http://localhost/images/json
## show in conprehensive format
curl --unix-socket /var/run/docker.sock http://localhost/images/json | jq .
#    --silent, -s
#    -XGET
```
---
* `docker ps`
```sh
curl --unix-socket /var/run/docker.sock http://localhost/containers/json
```

* `POST` to start/stop a container
```sh
curl -X POST --unix-socket /var/run/docker.sock http://localhost/containers/{id}/{start｜stop}
# or
curl -X POST --unix-socket /var/run/docker.sock http://localhost/containers/90c5ff77bc9f/stop
```

### FAQ
> 順便搞清楚一個常見問題:
1. 有個常見的問題相信大家都遇見過，執行docker命令時控制檯報錯如下：
```sh
[root@centos7 ~]# docker ps
Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?
```
此時的您一定很清楚問題原因了：Docker Daemon服務不正常，所以客戶端發送請求得不到響應
2. 用systemctl status docker命令看看Docker Daemon狀態，應該是停止或報錯：
```sh
[root@centos7 ~]# systemctl status docker
● docker.service - Docker Application Container Engine
   Loaded: loaded (/usr/lib/systemd/system/docker.service; enabled; vendor preset: disabled)
   Active: inactive (dead) since 六 2019-06-22 11:45:14 CST; 3min 58s ago
     Docs: http://docs.docker.com
  Process: 9134 ExecStart=/usr/bin/dockerd-current --add-runtime docker-runc=/usr/libexec/docker/docker-runc-current --default-runtime=docker-runc --exec-opt native.cgroupdriver=systemd --userland-proxy-path=/usr/libexec/docker/docker-proxy-current --init-path=/usr/libexec/docker/docker-init-current --seccomp-profile=/etc/docker/seccomp.json $OPTIONS $DOCKER_STORAGE_OPTIONS $DOCKER_NETWORK_OPTIONS $ADD_REGISTRY $BLOCK_REGISTRY $INSECURE_REGISTRY $REGISTRIES (code=exited, status=0/SUCCESS)
 Main PID: 9134 (code=exited, status=0/SUCCESS)
```
如果是停止狀態，執行systemctl start docker啓動服務即可，如果是錯誤就要case by case去分析了。

### 更多與Docker Daemon交互的請求
* [Docker Socket Request](https://docs.docker.com/engine/api/v1.41/)

### reference:
* [docker的/var/run/docker.sock參數](https://www.twblogs.net/a/5d0f0bbabd9eee1ede047312)