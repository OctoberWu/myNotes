keywords: rate-limit, throttling, burst

--- 
### Quick Note:
#### key factors  
* Logs
* Auth
* Trace
* Rate Limit
#### related terms
* rate limit (速度限制): 單位時間內的速度，單位通常是秒，常見的有述語有以下：
	* rps: request per second, 通常是網頁請求
	* qps: query per second, 通常是 database 的 query
	* tps: transcation per second, 每秒的交易數量，考驗分散式架構最關鍵的數字。
	* pv: page view, 網頁打開的次數，例如一天的 pv = 30k
* throttle: 中文是 節流閥 、俗稱油門，用來控制流速的增、減。
  * 想像是個閥門，打開後讓水流過去，閥門的高度決定水流的速度。
	* 在 Amazon API Gateway，就是最小單位 (1ms) 可以過去的數目
* burst limit: burst 中文翻成爆裂、爆走，突然的流量爆衝，但是暴衝還是要有限制，不然下一步就是爆炸 XDD
* steady-state rate: 穩態速率
* Levels in Amazon API Gateway: 分成 Account-Level Throttling 和 Stage-Level



### references:
* [API Gateway - Rate Limit and Throttling](https://rickhw.github.io/2018/05/03/AWS/Study-Notes-API-Gateway-Rate-Limit-and-Throttling/)