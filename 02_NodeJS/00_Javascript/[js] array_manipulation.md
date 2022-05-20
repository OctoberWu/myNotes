keywords: push(), unshift(), concat(), slice(), splice()


---
### quick note: 
使用slice(), splice(), 最值得區辨的特性是執行函數後回傳的物件，是否會影響原物件。

---
### Array.prototype.push()

---
### Array.prototype.unshift()
>  unshift() allows us to add items to *the beginning* of the array.
---
### Array.prototype.concat()

---
### Array.prototype.slice()
> slice() 方法會回傳一個新陣列物件，為原陣列選擇之 begin 至 end（不含 end）部分的淺拷貝（shallow copy）。而原本的陣列將不會被修改。

> The slice() method returns a shallow copy of a portion of an array into a new array object selected from begin to end (end not included). The original array will not be modified.

複製開始與結束點（結束點不算）中的內容

#### best practices
```js
arr.slice()
arr.slice(begin)
arr.slice(begin, end)
```

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

---
### Array.prototype.splice()
> The splice() method changes the contents of an array by removing existing elements and/or adding new elements.

從Array中添加/刪除項目，回傳被刪除的項目。
#### best practices:
```js
array.splice(start)
array.splice(start, deleteCount)
array.splice(start, deleteCount, item1, item2, ...)
```

* Examples:
```js
// Remove last element from Array
array.splice(-1)
// or
array.splice(-1,1);
// or
array.pop();
```

