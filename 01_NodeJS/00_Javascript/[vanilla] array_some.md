keywords: array_prototype_some

---
### Detect whether two arrays have elements in common 
```js 
// Not Supported in IE 6-11
const arr1 = ['pizza', 'cake', 'cola'];
const arr2 = ['pizza', 'beer'];

const contains = arr1.some(element => {
  return arr2.includes(element);
});

console.log(contains); // 👉️ true
```
