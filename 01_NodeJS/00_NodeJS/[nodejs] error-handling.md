keywords: error-handling, exception-handling

---

### Quick Note:

#### front-end
  * ​​Utility library (lodash)
	* Short-circuiting with &&
	* The “Maybe Monad”
	```js
	const favoriteBook = ((favorites.reading||{}).books||[])[0]; // undefined
  const favoriteAudiobook = ((favorites.audio||{}).audiobooks||[])[0]; // undefined
  const favoritePodcast = ((favorites.audio||{}).podcasts||[])[0]; // 'Shop Talk Show'
	```
	* try/catch
	* Merge with a default object
	```js
	const defaults = {
		position: "static",
		background: "transparent",
		border: "none",
	};

	const settings = {
		border: "1px solid blue",
	};

	const merged = { ...defaults, ...settings };

	console.log(merged); 
	/*
	{
		position: "static",
		background: "transparent",
		border: "1px solid blue"
	}
	*/	
	```



### references
  * [JavaScript 深入淺出 Error & Exception-Handling 錯誤與例外處理](https://shawnlin0201.github.io/JavaScript/JavaScript-Exception-Handling/)
  * [How to Build a Node.js Error-handling System](https://www.toptal.com/nodejs/node-js-error-handling)
	* [How to Handle Errors in an Express and Node.js App](https://levelup.gitconnected.com/how-to-handle-errors-in-an-express-and-node-js-app-cb4fe2907ed9)
	* [Avoiding those dang cannot read property of undefined errors](https://css-tricks.com/%E2%80%8B%E2%80%8Bavoiding-those-dang-cannot-read-property-of-undefined-errors/)
	* [Cleaner Exception Handling in JavaScript](https://paulallies.medium.com/functional-exception-handling-in-javascript-with-the-either-monad-3fb596c73912)