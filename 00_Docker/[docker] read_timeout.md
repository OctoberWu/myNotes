keywords: read-timeout

---
### quick note:

#### issue:
```shell
ERROR: for fb_0_service  UnixHTTPConnectionPool(host='localhost', port=None): Read timed out. (read timeout=70)
ERROR: An HTTP request took too long to complete. Retry with --verbose to obtain debug information.
```

#### solution:
* method 1:
```text
export DOCKER_CLIENT_TIMEOUT=500
export COMPOSE_HTTP_TIMEOUT=500
```

* method 2:
```shell
sudo vim /etc/profile
# append the text below onto the file
export DOCKER_CLIENT_TIMEOUT=500
export COMPOSE_HTTP_TIMEOUT=500
# rerun docker-compose
```


### reference:
* [解決因為機器效能問題導致docker-compose執行容器超時的問題](https://www.gushiciku.cn/pl/27Yf/zh-tw)