### Installation

```sh
## install from apt sever
$sudo apt-get install redis

## run in daemon
$redis-server & 
## check if the process started or not
$ps aux | grep redis-server
# or
$ps -ef | grep redis-server

## stop redis
$redis-cli
> 127.0.0.1:6379> shutdown
```

### redis 基礎入門：
https://itnext.io/redis-5-x-under-the-hood-1-downloading-and-installing-redis-locally-3373fe67a154

### redis modules
1. sql with sqlite3 embedded
2. graph 
Redis 5.X under the hood: 3 — Writing a Redis Module[https://itnext.io/redis-5-x-under-the-hood-3-writing-a-redis-module-43fa42a6367d]

---
### write-through cache
Redis is increasingly used as a `caching layer`, much like a more sophisticated memcached, and is very useful in this role. 
* You usually use
	* Redis as a `write-through cache` for data you want to be durable, and 
	* write-back for data you might want to accumulate then batch write (where you can afford to lose recent data).

ref: https://stackoverflow.com/questions/17033031/can-redis-write-out-to-a-database-like-postgresql