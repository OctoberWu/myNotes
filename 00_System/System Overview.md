### Messaging Network
1. Making cache for system program. Enhance system performance，at the same time could be Message Broker as well.
* A cache is just fast storage
2. Cache options(nodejs, python):
* memcached 
* redis
3. MQ options:
* Rabbit MQ
4. more... 

### Cache strategies 
* LRU Eviction(Least Recently Used)

--- 

### Graph Network Visualization
1. Graph Network Visualization Framework options:
* D3.js - Graph Network, SVG support
* vis.js
* v-network, vue-based
2. more...

### Canvas update frame optimization 
1. Off-screen canvas
2. Offscrenn canavs + Web Worker (!! not mature yet, not supported by every browser) 
   * [OffscreenCanvas — Speed up Your Canvas Operations with a Web Worker](https://developer.chrome.com/blog/offscreen-canvas/)
3. set the coordinates without floating points. 
4. rendering canvs on server side

---
### NPM Resources:
#### Cache
1. memecached (https://www.npmjs.com/package/memcached)
2. express-session + memcached (https://blog.benhall.me.uk/2012/01/caching-with-memcached-express-and-nodejs/)