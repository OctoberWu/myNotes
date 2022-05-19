### generate universal unique id

Note: 
1. javascript does not have a built-in method for generating unique id.
2. take Math.random() instead


```js
	function generate() {
		let id = () => {
			return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);
		}
	}
```