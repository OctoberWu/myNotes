keywords: recursively run async function in javascript

---
### Recursively run async function in javascript
* in one file
```javascript 
// Recursively run async function
const timeout = ms => new Promise((resolve) => setTimeout(resolve, ms));

async function recursion(value) {
	if (value === 0) { return 0; }
	await timeout(1000);
	return value + await recursion(value - 1);
}

(async () => console.log(await recursion(3)))();
```

* separated files with `class` keyword
###### child process
```js
class Test {
	constructor() { }

  timeout = ms => new Promise((resolve) => setTimeout(resolve, ms));

	async recursion(value) {
		if (value === 0) { return 0; }
		await this.timeout(1000);
		return value + await this.recursion(value - 1);
	}

	async supervise() {
		console.log(await this.recursion(3));
	}

}

const test = new Test();
module.exports = test;
```

###### main thread
```js
const child = require('./childProcess');
child.supervise();
```

### side note for class keyword for javasript
* static in member function in js
  * only invoked by class
* async decorator is allowed for member function in class

### How to use `setTimeout` synchronously in javascript
```javascript
const sleep = (ms) => {
  return new Promise((resolve) => setTimeout(resolve, ms));
};

const demo = async () => {
  console.log("this should be the first one");
  await sleep(5000);
  console.log("this should be the second one");
};

demo();
```
* more detail: https://javascript.info/settimeout-setinterval