keywords: Object.keys(), Object.values, Object.entries(), shallow-copy, deep-copy


--- 
### Quick Note:
將 JS 物件轉成其他資料結構，所以需要迭代物件中的所有 property，過去會用 for-in 陳述句，但只想列舉 own property，就必須用 hasOwnProperty() 才能解決。後來 ES5 新增的 Object.keys() 解決了非 own property 的問題，但還是要手動透過 property name 來存取 value，不方便！終於在 ES2017 (ES8) 新增了 Object.values() 和 Object.entries()，可以直接取得 property value 了！

* Object.keys():  將 JSON Object中的所有key值拿出，組成一個陣列。

* Object.values(): 將 JSON Object中的所有values值拿出，組成一個陣列。 

* Object.entries():  將 JSON Object中的所有<key>:<value> 的pair拿出，組成一個陣列。


### references:
* [JavaScript 之旅 (4)：Object.keys() & Object.values() & Object.entries()](https://ithelp.ithome.com.tw/articles/10239942)
* [JS 中的淺拷貝 (Shallow copy) 與深拷貝 (Deep copy) 原理與實作](https://www.programfarmer.com/articles/javaScript/javascript-shallow-copy-deep-copy)