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