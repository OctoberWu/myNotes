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

### optimization:
* [map graph] 更新graph上面的 robot 及使用中的edge，通過 node 以圖片的形式出現，定時更新，位置。

### keywors:
* congestion-free 


### Reactive, Actor Framework (CAF[c++ actor framework])
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

#### conceptually idea to implement reactive routing
1. 建立 Graph
2. 運用time frame，顯示不同時間戳記下的空間分佈。
3. 用不同顏色，顯示不同 robot agent 的 ownership 
4. Reporting
5. coordinations