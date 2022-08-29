keywords: capitalized words

---
### capticalized the very first word in a string
```javascript
$(document).find('.card-title > span').each(function () {
	// --- font-text, font-family spec. ---
	let title = $(this).text().trim().toLowerCase();
	title = title[0].toUpperCase() + title.slice(1);
	$(this).text(title)
	$(this).css("font-family", "Arial");
});
```

### capticalized words in a string
```javascript
$(document).find('.card-title > span').each(function () {
	// --- font-text, font-family spec. ---
	let title = $(this).text().trim().toLowerCase();
	title = title.replace(/\b\w/g, l => l.toUpperCase())
	$(this).text(title)
	$(this).css("font-family", "Arial");
});
```

---
### GUID/UUID
GUID: Globally-Unique IDentifiers 
UUID: Universally Unique IDentifiers

UUID 包含 32 個十六進位數字，並用「-」分隔成五組，每組分別有8、4、4、4、12的數字。例如：「550e8400-e29b-41d4-a716-446655440000」是一組完整的 UUID。

#### Method1
```javascript
function _uuid() {
  function s4() {
    return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);
  }
  return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();
}

var uuid = _uuid(); //b3165466-df5b-c3d7-0e94-79d94e8c692f
```
cons:
* 格式不符合 RFC4122 規範
* Math.random() 產出的數字可能重覆 (collision)，儲存前必須做比對

---

#### Method2
```javascript
function _uuid() {
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {var r = Math.random()*16|0,v=c=='x'?r:r&0x3|0x8;return v.toString(16);});
}

var uuid = _uuid(); //5fc84f46-5743-4ed3-a94d-1ba63b8022a5f
```
pros:
* 先擺好格式，再利用 Math.random() 產出任意數字填入格式中。這個方法解決了方法 1 的格式問題，
cons:
* 仍可能有 collision。

---

#### Method3
```javascript
function _uuid() {
  var d = Date.now();
  if (typeof performance !== 'undefined' && typeof performance.now === 'function'){
    d += performance.now(); //use high-precision timer if available
  }
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function (c) {
    var r = (d + Math.random() * 16) % 16 | 0;
    d = Math.floor(d / 16);
      return (c === 'x' ? r : (r & 0x3 | 0x8)).toString(16);
  });
}
```
* 結合 time stamp 與方法 2，同時解決了格式和 collision 問題。
* 加上 Performance.now() (亞毫秒級的時間戳記)，很難產生 collision。
* 主流瀏覽器皆支援，但 IE 只支援 10 以上或 Edge。


[如何用 JavaScript 產生 UUID / GUID？](https://cythilya.github.io/2017/03/12/uuid/)

