keywords: jquery-selector, select-in-regular-express

---
### quick note:
* Not-Equal selector
	* Attribute Not Equal Selector [name!=”value”]

```js
var nodes = $('div[id^="node-"]').filter(':not(#node-2)').filter(':not(#node-3)');
```