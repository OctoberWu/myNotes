### Flatten Array
```js
// array spread method
var taskList=[];
for(f of tasks){
  taskList.push(...(f.tasks));
}

// Native Array Prototype(ES 2019)
var taskList = tasks.map(f=>f.tasks).flat();

// lodash
var taskList = _.map(tasks, f=>f.tasks);
taskList = _.flatten(taskList);
```
---
#### Official Example
```js
// Requiring the lodash library
const _ = require("lodash");
  
// Original array
let array1 = [[1, 2], [4, 5], [7, 8]]
  
// Using _.flatten() method
let newArray = _.flatten(array1);
  
// Printing original Array
console.log("original Array1: ", array1)
  
// Printing the newArray
console.log("new Array: ", newArray)
```

--- 
### use `concat` to merge arrays
```js
var arrays = [
  ["$6"],
  ["$12"],
  ["$25"],
  ["$25"],
  ["$18"],
  ["$22"],
  ["$10"]
];
var merged = [].concat.apply([], arrays);

console.log(merged);
```

> There is also the Array.prototype.flat() method (introduced in ES2019) which you could use to flatten the arrays, although it is only available in Node.js starting with version 11, and not at all in Internet Explorer.

```js
const arrays = [
      ["$6"],
      ["$12"],
      ["$25"],
      ["$25"],
      ["$18"],
      ["$22"],
      ["$10"]
    ];
const merge3 = arrays.flat(1); //The depth level specifying how deep a nested array structure should be flattened. Defaults to 1.
console.log(merge3);
```    