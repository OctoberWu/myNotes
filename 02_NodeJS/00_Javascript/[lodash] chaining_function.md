
1. lodash chain basics, and what to know first
	1-1. Explicit Chaining with _.chain
	```js
	let arr = _.chain([1, 2, 3, 4])
			.map((n) => {
					return Math.pow(2, n);
			})
			.filter((n) => {
					return n % 8 === 0;
			})
			.sum();
	
	// we have an wrapped object
	// and not a final value
	console.log(arr); // { Object }
	
	// I must call value() to get what I want
	console.log(arr.value()); // 24
	```
1-2. Implicit Chaining with the main lodash method _()
	```js
	let arr = _([1, 2, 3, 4])
			.map((n) => {
					return Math.pow(2, n);
			})
			.filter((n) => {
					return n % 8 === 0;
			})
			.sum();
	console.log(arr); // 24
	```
2. Chaining with Native array methods
	```js
	let arr = [1, 2, 3, 4]
	.map((n) => {
			return Math.pow(2, n);
	})
	.filter((n) => {
			return n % 8 === 0;
	})
	.reduce((acc, n) => {
			return acc + n
	});
	
	console.log(arr);
	```

### quick note:
* filter out keys in JSON object, could use lodash `_.pickBy()` method.

---
### References:
* [Chaining functions in javaScript with lodash or not](https://dustinpfister.github.io/2018/11/11/lodash_chain/)
* [How to Filter Keys of an Object with Lodash?](https://thewebdev.info/2021/04/11/how-to-filter-keys-of-an-object-with-lodash/)
