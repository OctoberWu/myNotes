keywords: nodelist, array

--- 
### convert a NodeList to an array in JavaScript
> [...] a NodeList is a collection of nodes that can be used to access and manipulate DOM elements, while an array is a JavaScript object which can hold more than one value at a time.

> Both NodeLists and arrays have their own prototypes, methods, and properties. You can easily convert a NodeList to an array if you want to, but not the other way around.

### `Array.from()` Method
```js 
// create a `NodeList` object
const divs = document.querySelectorAll('div');

// convert `NodeList` to an array
const divsArr = Array.from(divs);
```

### Spread Operator
```js
// create a `NodeList` object
const divs = document.querySelectorAll('div');

// convert `NodeList` to an array
const divsArr = [...divs];
// or 
const divsArr = [...document.querySelectorAll('div')];
```

### `Array.prototype.slice()` Method
```js
// create a `NodeList` object
const divs = document.querySelectorAll('div');

// convert `NodeList` to an array
const divsArr = Array.prototype.slice.call(divs);

// can also use a concise form of the above method:
const divsArr = [].slice.call(divs);
```

### `Array.prototype.slice()` Method
```js 
const nodelist = document.querySelectorAll('div');
const nodelistToArray = Array.apply(null, nodelist);

// then
nodelistToArray.forEach(...);
nodelistToArray.map(...);
nodelistToArray.slice(...);
```


references:
* [How to convert a NodeList to an array in JavaScript](https://attacomsian.com/blog/javascript-convert-nodelist-to-array)