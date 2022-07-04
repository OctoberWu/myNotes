keywords: graph-manipulation, vis-js, remove-edge, remove-node

--- 
### quick note:
* sample code
```js
  var cellObjArr = jsonNavGraphCache_.nodes;
  // var myNodes = cellObjArr.find(n => n.cell_id === 'a_temp_cell2');
  var myNode = cellObjArr.find(n => n.cell_id === params.controlEdge.to);
  if (myNode !== undefined) { return; }
  
  // ===================================
  let edges = visNetwork_.body.edges;
  let edgeArr = Object.values(edges);
  let targetEdge = edgeArr.find(e => e.fromId === params.controlEdge.from && e.toId === params.controlEdge.to);
  visNetwork_.body.data.edges.remove([targetEdge.id]); // << CRITICAL API to remove edge from graph>>
  return;
```