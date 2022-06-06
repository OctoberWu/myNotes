keywords: array refactor

---
### quick note:
#### array-refactor
```js
  // === remove cell uuid attributes ===
  // --- previous way ---
  // for (areaKey in jsonCellCache_) {
  //   for (cellKey in jsonCellCache_[areaKey]) {
  //     // remove json cache cell uuid before saving map json file
  //     if (jsonCellCache_[areaKey][cellKey].hasOwnProperty('cell_uuid')) {
  //       delete jsonCellCache_[areaKey][cellKey]['cell_uuid'];
  //     }
  //     // // replace old cell load before saving map json file
  //     // if (jsonCellCache_[areaKey][cellKey].hasOwnProperty('load')) {
  //     //   jsonCellCache_[areaKey][cellKey]['load'] = jsonCellCache_[areaKey][cellKey]['load'].replace('rack', 'occupied');
  //     // }
  //   }
  // }

  // --- updated way ---
  for (let key of Object.keys(jsonCellCache_)) {
    jsonCellCache_[key] = jsonCellCache_[key].map(av => _.omit(av, ['cell_uuid']));
  }
  console.log(jsonCellCache_);
```

#### restfult-api refactor
* to get the json-format response instead of string.
```js
function restPostFunctionTypes(_data) {
  console.log(_data);
  return $.ajax({
    url: '/swarm/functionTypes',
    type: 'POST',
    contentType: 'application/json',
    async: true,
    data: JSON.stringify(_data),
    success: function (data) {
      console.log("--- get role in-used operations check ---");
    }
  });
  // return $.post('/swarm/functionTypes', {
  //   content: _data,
  //   contentType: 'application/json'
  // }, function (data, status) {
  //   console.log("--- function-types post ---");
  // });
}
```