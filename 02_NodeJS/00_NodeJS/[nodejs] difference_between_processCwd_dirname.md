keywords: process.cwd(), __dirname

---
### The difference between process.cwd() and __dirname
* The difference between
```javascript
console.log(process.cwd())
console.log(__dirname);
```

#### Answer:
* `process.cwd()` returns the current working directory,
> i.e. the directory from which you invoked the node command.

* `__dirname` returns the directory name of the directory containing the JavaScript source code file

Note: 
1. 用於作相對路徑上，`process.cwd()`十分有幫助，打包後的執行檔(*.exe)的相鄰資料夾路徑，即可用此。
