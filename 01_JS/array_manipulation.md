keywords: push(), unshift(), concat(), splice(), slice()


---
### Array.prototype.push()

---
### Array.prototype.unshift()
>  unshift() allows us to add items to *the beginning* of the array.
---
### Array.prototype.concat()

---
### Array.prototype.splice()

* Examples:
```js
// Remove last element from Array
array.splice(-1)
// or
array.splice(-1,1);
// or
array.pop();
```

---
### Array.prototype.slice()
> slice() 方法會回傳一個新陣列物件，為原陣列選擇之 begin 至 end（不含 end）部分的淺拷貝（shallow copy）。而原本的陣列將不會被修改。


* Examples:
```js
const animals = ['ant', 'bison', 'camel', 'duck', 'elephant'];

console.log(animals.slice(2));
// expected output: Array ["camel", "duck", "elephant"]

console.log(animals.slice(2, 4));
// expected output: Array ["camel", "duck"]

console.log(animals.slice(1, 5));
// expected output: Array ["bison", "camel", "duck", "elephant"]

console.log(animals.slice(-2));
// expected output: Array ["duck", "elephant"]

console.log(animals.slice(2, -1));
// expected output: Array ["camel", "duck"]

console.log(animals.slice());
// expected output: Array ["ant", "bison", "camel", "duck", "elephant"]
```