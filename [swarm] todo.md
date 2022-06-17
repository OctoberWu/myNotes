keywords: improvements, todo, missing-features, 

--- 
### TODOs
- [x] schema validator by `yup` module
- [ ] remove tasks in job on operation page
- [ ] RESTful API by `axios` module
- [ ] operatFormatter(), 的事件觸發，不能頻繁的更新。

- [ ] 長時間處理請求。
> 使用RESTful API進行長時間的請求，更新狀態。 使用SSE

### known issues:
* when need to do updates, the network has to be set to `host` instead of `bridge`.
	- directory: farobot_dev_env > docker-services > base_service > base-service.yml.	
		- services > base_service > network_mode > host


