keywords: triaffic, network-routing, 

---
#### summary:
* delivery flow control
* network capacity analysis
  - how many deliver flows is available
	- what to do when the capacity is insufficient?

* reachability. end-to-end reachability rate
* weighting > lane width

* capacity is more related to the edges

* delivery flow (task) estimation, 
  * existing terminal to terminal
	* endpoints (terminal) management  

* if the priority is higher, then rearrange the routes (edges re-allocation), and the running task updating the route from the next node
* what if the communication(sync-up) is failed, then from the higher priority will draw back

priority ranking:
* EMERGENCY
	- running task be offline suddenly or a while (?) > 不正常連線、網路斷開、機器突然故障
		- 補救措施。走到下一個點(node)， 等待網路恢復。
* NORMAL
	- priority task

features: 
* 可動態加入 edges and node 進入 graph
* 可動態調整任務的經過的路線。
* 動態意指，可在執行過程中，動態更新(新增、刪除)資源。
* agent性能 與 任務內容 的匹配。