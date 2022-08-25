keywords: improvements, todo, missing-features, 

--- 
### TODOs
- [x] schema validator by `yup` module
- [ ] remove tasks in job on operation page
- [ ] RESTful API by `axios` module
- [ ] operatFormatter(), 的事件觸發，不能頻繁的更新。

- [ ] 長時間處理請求。
> 使用RESTful API進行長時間的請求，更新狀態。 使用SSE
- [ ] control-list for debian packages
- [ ] robot physical configuration 
- [v] 長時間大資料量的對策。刪除資料筆數的操作，只保持最近幾筆的資料，超過的筆數，一律刪除。當資料太大，請求超時重覆發出刪除指令時，並不會移除最新的10000筆資料。
- [v] visNetwork, Multiple event bindings. Have to `off` before binding.

### known issues:
* when need to do updates, the network has to be set to `host` instead of `bridge`.
	- directory: farobot_dev_env > docker-services > base_service > base-service.yml.	
		- services > base_service > network_mode > host


Relation tables is hard to describe further hierarchy structure
each column is hard to accommodate more further hierarchy. 
and the elements has many, then it becomes more complex operate the data
graph may be more suitable for solving such cases.


* replace the communication pub/sub mechanism in docker containers
	1. switch the mode from `bridge` to `host`
	2. the sample codes are tested in `ros_mocks_ws > py_pubsub`
	3. add docker-compose ports: 5672, 15672
	

* Variables Configuration
 - [nodejs]  node-config

* 使用SQL與NoSQL資料庫的差別。對於資料的結構化程度不同
  - SQL對於資料的結構化程度較高。目前SQL已有些產品可支援JSON Object，但對於更剛彈性的資料結構，就顯得不足。
	- No SQL能夠容許更高的資料結構的變化。JSON的結構，能夠更加的彈性及擴充。

### 使用RESTful API，需注意的細節。
一般使用fetch，拿到返回的資料時。需留意其資料格式為JSON or non-JSON。

example:
```js
function fetchPutMapGraph(_token, _mapName, _mapGraph) {
	return fetch(`http://${window.location.hostname}:5000/v2/maps/${_mapName}/graph`, {
		method: "PUT",
		headers: {
			accept: "application/json",
			authorization: `${_token.token_type} ${_token.access_token}`,
			'Content-Type': 'application/json',
		},
		body: `{ "content": "${_mapGraph}" }`
										// ^^^          ^^^  <--- 記得留意是否有正確加上quotation!!
	})
		.then((response) => { return response; });
}
```


#### 處理 Request 的資料
* 需留意發送請求時，的字符串是否符合JSON的規範。一般換行符為'\n'，而JSON的換行符為'\\n'，

#### 處理 Response的資料
* JSON
```js
let res = await fetchData();
res = await res.json();
console.log(res);
```
* non-JSON
```js
let res = await fetchData();
res = await res.json();
res = await res.text();
console.log(res);
```

#### Auto-format in VSCode 
* On Windows `Shift + Alt + F`
* On Mac `Shift + Option + F`
* On Linux `Ctrl + Shift + I`

### swarm traffic analysis and concepts:
0. Infrastructure
    * configuration, graph structure(node size, edge width) setup
1. Capacity Evaluation
    * graph structure analysis vs. agent amount capacity
2. Realtime Traffic Monitoring
    * failed / disconnected handling(fail-over)
3. Reactive Routing
    * asynchronous routing, dynamic, responsive
4. On-Demand Coordination Strategies
    * optimization factors. efficiency, less-space, priority-based(on-demand)