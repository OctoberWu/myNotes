keywords: exception, handling, error-handling, exceptional handling

---
## Error/Exceptional handling
### 7 Types of Error
1. Error
2. RangeError
3. ReferenceError(找不到變數, 拼錯字)
4. SyntaxError
5. TypeError
6. URIError
7. EvalError


---
### Handling Exceptions (處理錯誤)
* `try...catch...finally`
```js
try {
  // attempt to execute this code
} catch (exception) {
  // this code handles exceptions
} finally {
  // this code always gets executed
}
```

### Thowing Exceptions (客製化錯誤)
> Use `throw` to show the exceptional case.

```js
let denominator = 0

// RangeError: Attempted division by zero!
try {
  if (denominator === 0) {
    throw new RangeError("Attempted division by zero!");
  }
} catch (e) {
  console.log(e.name + ': ' + e.message)
}
```

* errorName (客製化錯誤名稱)
```js
/**
 * 客製化錯誤類型
 **/
function DivisionByZeroError(message) {
  this.name = 'DivisionByZeroError';
  this.message = message;
}

// 繼承 Error 物件
DivisionByZeroError.prototype = new Error();
DivisionByZeroError.prototype.constructor = DivisionByZeroError;

// 建立 showError 的方法
DivisionByZeroError.prototype.showError = function() {
  return this.name + ': "' + this.message + '"';
}
```
* Use it!
```js
let denominator = 0

try {
  if (denominator === 0) {
    throw new DivisionByZeroError("Attempted division by zero!");
  }
}
catch (e) {
  console.log(e.showError())  // DivisionByZeroError: "Attempted division by zero!"
}
```

### Others
* 透過 instanceof 處理多種不同的錯誤類型
利用 instanceof 可以根據不同的錯誤類型執行不同的 catch

```js
try {
    // assume an exception occurs
} catch (exception) {
  if (exception instanceof TypeError) {
      // Handle TypeError exceptions
  } else if (exception instanceof ReferenceError) {
      // Handle ReferenceError exceptions
  } else {
      // Handle all other types of exceptions
  }
}
```