keywords: load_execution_sequence, on_load, document_ready

---
### JavaScript window.onload 和 jQuery $(document).ready() 的差異


在撰寫頁面的JavaScript或jQuery時，通常會利用window.onload事件或$(document).ready()事件來確保DOM完全載入，不過兩者仍有以下差異。

window.onload會等網頁的全部內容，包括圖片，CSS及<iframe>等外部內容載入後才會觸發，但$(document).ready()在Document Object Model (DOM) 載入後就會觸發，所以順序上$(document).ready()會比window.onload先執行。

window.onload是JavaScript的原生事件，而$(document).ready()是jQuery的事件（其實是透過監聽JavaScript的DOMContentLoaded事件來實現）。
--- 
* window.onload的用法如下：
```js
window.onload = function() {
  // console.log("window loaded")
};
```

* $(document).ready()的用法如下：
```js
$(document).ready(function() {
  // console.log("document ready");
});
// 也可簡寫成
$(function() {
  console.log("document ready");
});
```


Ref:
* [JavaScript window.onload 和 jQuery $(document).ready() 的差異](https://matthung0807.blogspot.com/2018/02/javascript-windowonload-jquery.html)
* [Load and execution sequence of a web page?](https://stackoverflow.com/questions/1795438/load-and-execution-sequence-of-a-web-page?rq=1)