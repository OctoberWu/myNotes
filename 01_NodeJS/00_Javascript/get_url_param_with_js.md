How to Get URL Parameters with JavaScript
=========================================

### Assuming that our URL is https://example.com/?product=shirt&color=blue&newuser&size=m, we can grab the query string using window.location.search:
```js 
const queryString = window.location.search;
console.log(queryString);
// ?product=shirt&color=blue&newuser&size=m
```
---
### We can then parse the query string’s parameters using URLSearchParams:
```js 
const urlParams = new URLSearchParams(queryString);
```
Then we call any of its methods on the result.

### For example, URLSearchParams.get() will return the first value associated with the given search parameter:

```js 
const product = urlParams.get('product')
console.log(product);
// shirt

const color = urlParams.get('color')
console.log(color);
// blue

const newUser = urlParams.get('newuser')
console.log(newUser);
// empty string
```

reference:
* [How to Get URL Parameters with JavaScript](https://www.sitepoint.com/get-url-parameters-with-javascript/)