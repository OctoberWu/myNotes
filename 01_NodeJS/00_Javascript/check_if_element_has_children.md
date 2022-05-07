keywords: child_elements, js

---
### How to check if element has any children in Javascript?
Sol:
```js
if (element.firstChild) {
    // It has at least one
}
or the hasChildNodes() function:

if (element.hasChildNodes()) {
    // It has at least one
}
or the length property of childNodes:

if (element.childNodes.length > 0) { // Or just `if (element.childNodes.length)`
    // It has at least one
}
```


reference: 
* [How to check if element has any children in Javascript?](https://stackoverflow.com/questions/2161634/how-to-check-if-element-has-any-children-in-javascript)