keywords: websockets, back-pressure, SSE, network, traffic, load-testing, artillery, autocannon

---
### quick note:
* websocket 是無法透過程式，清理buffer, 故無法通過 flow-control 作 buffer 清理
* uWebsocket 是目前評比最佳的專案。

### http benchmarking tool 
> traffic load testing 
* autocannon
* clinic

### references:

#### websockets Introduction
* [websockets](https://medium.com/voodoo-engineering/websockets-on-production-with-node-js-bdc82d07bb9f)
* [The story of “uws” so far](https://alexhultman.medium.com/the-story-of-uws-so-far-493ac0c05ccb)
* [Introducing Improved Web Socket Server](http://www.antradar.com/blog-introducing-improved-web-socket-server)

#### performance benchmark, SSE
* [Polling vs SSE vs WebSocket— How to choose the right one](https://codeburst.io/polling-vs-sse-vs-websocket-how-to-choose-the-right-one-1859e4e13bd9)
* [Websocket Performance Comparison](https://matttomasetti.medium.com/websocket-performance-comparison-10dc89367055)
* [HTTP vs Websockets: A performance comparison](https://blog.feathersjs.com/http-vs-websockets-a-performance-comparison-da2533f13a77)
* [Serving 100k requests/second from a fanless Raspberry Pi 4 over Ethernet](https://levelup.gitconnected.com/serving-100k-requests-second-from-a-fanless-raspberry-pi-4-over-ethernet-fdd2c2e05a1e)
* [How JavaScript works: Deep dive into WebSockets and HTTP/2 with SSE + how to pick the right path](https://blog.sessionstack.com/how-javascript-works-deep-dive-into-websockets-and-http-2-with-sse-how-to-pick-the-right-path-584e6b8e3bf7)
* [Benchmarking websocket server performance with Artillery](https://ma.ttias.be/benchmarking-websocket-server-performance-with-artillery/)
* [BENCHMARKING WEBSOCKETS AVEC NODEJS](https://tech.bedrockstreaming.com/benchmarking-websockets-avec-nodejs)

#### buffer-clean, back-pressure
* [How to clear buffer on websocket?](https://stackoverflow.com/questions/47897486/how-to-clear-buffer-on-websocket)
* [Can I have flow control on my websockets?](https://stackoverflow.com/questions/19414277/can-i-have-flow-control-on-my-websockets)
* [Does NodeJS WebSockets (ws) module implement backpressure?](https://stackoverflow.com/questions/55188328/does-nodejs-websockets-ws-module-implement-backpressure)
* [Beware of uWebsockets.js!](https://medium.com/@rockstudillo/beware-of-uwebsockets-js-b51c92cac83f)
* [Backpressure explained — the resisted flow of data through software](https://medium.com/@jayphelps/backpressure-explained-the-flow-of-data-through-software-2350b3e77ce7)
* [Backpressuring in Streams](https://nodejs.org/en/docs/guides/backpressuring-in-streams/)


#### projects
* [joewalnes/websocketd](https://github.com/joewalnes/websocketd)

