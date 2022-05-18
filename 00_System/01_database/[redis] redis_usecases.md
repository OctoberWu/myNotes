keywords: redis, cache, pub-sub, websocket, scalability

--- 
### quick note:
通過使用 redis-rdb-tools + sqlite 的方式，可以方便的對 redis 實例的內存情況進行靜態的分析。整個過程也比較簡單，獲取到 rdb 之後即可。

### references:
* [Using Redis pub/sub with Node.js](https://blog.logrocket.com/using-redis-pub-sub-node-js/)
* [Caching In Node.js Applications](https://www.honeybadger.io/blog/nodejs-caching/)
* [Easy real-time messaging system with Python and Nodejs (Redis Pub/Sub Tutorial)](https://medium.com/codex/easy-real-time-messaging-system-with-python-and-nodejs-redis-pub-sub-tutorial-6d43f5f4c75a)
* [How to Cache API Requests with Redis and Node.js](https://javascript.plainenglish.io/how-to-cache-api-requests-with-redis-and-node-js-385cee0edff7)
* [A simple caching strategy for Node REST APIs, Part 1](https://dev.to/vigzmv/a-simple-caching-strategy-for-node-rest-apis-part-1-72a)
* [CachesExplained](https://github.com/google/guava/wiki/CachesExplained)
* [Powerful Caching with Redis for Node.js Applications](https://blog.appsignal.com/2021/03/10/powerful-caching-with-redis-in-node.html)
* [Scaling node.js websocket applications with redis](https://www.ibuild.services/scalable-websocket-application-with-node-js-and-redis/)
* [Redis 內存分析方法](https://www.twblogs.net/a/5c21f0aabd9eee16b3dae8fe)

#### scalability
* [Building a Scalable API in Node](https://medium.com/swlh/building-a-scalable-api-in-node-41c65f84d9c1)
* [Building Reliable and Scalable APIs with Node.JS](https://medium.com/swlh/building-a-simple-and-reliable-api-with-node-js-650ee6290fe6)

#### Distributed lock 
* [Everything I know about distributed locks](https://davidecerbo.medium.com/everything-i-know-about-distributed-locks-2bf54de2df71)
* [Redis Lock (Redlock) 分散式 lock 原理分析與實作](https://yuanchieh.page/posts/2020/2020-01-14_redis-lock-redlock-%E5%8E%9F%E7%90%86%E5%88%86%E6%9E%90%E8%88%87%E5%AF%A6%E4%BD%9C/)