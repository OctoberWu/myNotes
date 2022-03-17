### TODO LIST:
[] setInterval > setTimeout
comments: 
* [error-prone] setInterval的管理會較為麻煩。
* [error-prone] 且容易額外多出許多預期外的timer

[] restful api > axios
comments:
* 併發效率較高

[] 優化canvas更新的速率 (virtual joystick as well?)

[x] WebSocket 的 heartbeat。終結壞掉的連結(bad connection)
comment:
* 必須留意在 websocket on-connection，不要產生timer，避免memory leak。

[] (知識點) WebSockets有流量的限制與阻塞嘛？
comments:
* 基於實做不同而不同，一般來說沒有。
[Does WebSockets have a throughput limit?](https://stackoverflow.com/questions/17290687/does-websockets-have-a-throughput-limit)