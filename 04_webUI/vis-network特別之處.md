1. 在使用vis-network編輯後，進行除錯後。
console.log(network2_.body.nodes)印出來的值並非是過去那個除錯點的值，而是更新後的最新值。

2. network2_.getPosition(). 僅將graph所有的點列出

3. network2_.getConnectedNodes(elem.id); 無法將單向的edge反應出來。只會提供雙向的連結的關係。
會將該node連結到的edge都加進去(from, to)，從而無法得uni-direction的edge