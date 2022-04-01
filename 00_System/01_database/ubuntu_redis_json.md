### Environment
* Ubuntu 20.04.2

### Redis Installation
```sh
sudo apt isntall redis
```

### Redis Module Installation 
* download rejson module
github: https://github.com/RedisJSON/RedisJSON/releases
or 

* download by wget
```sh
wget https://github.com/RedisJSON/RedisJSON/archive/refs/tags/v1.0.7.tar.gz
```

* Decompression
```sh
tar xf v1.0.7.tar.gz
```

* compilation
```sh
cd ./RedisJSON-1.0.7
make
### enter ./src to get rejson.so
```

### Rejson configuration
```sh
### copy rejson.so to /usr/lib/
sudo cp ./src/rejson.so /usr/lib
### edit /etc/redis/redis.conf
sudo vim /etc/redis/redis.conf
### append below to redis.conf
`loadmodule /usr/lib/rejson.so`
#### or
$ redis-server --loadmodule /usr/lib/rejson.so
```

---
### Function Test

```sh
redis-cli
### command
json.set abc . '{"a":"1","b":"2",,"c":"3"}'
```

---
### How to stop redis-server
```sh
/etc/init.d/redis-server restart

# stop/start it:
/etc/init.d/redis-server stop
/etc/init.d/redis-server start
```

---
### running database server in docker container
```sh
docker run -it --rm -d --name my-redis -p 6379:6379 redis
```
| params | features                 |
| ------ | ------------------------ |
| -it    | interactive              |
| -rm    | remove while termination |
| -d     | daemon mode              |
| -name  | container name           |
| -p     | port                     |
