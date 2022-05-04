keywords: check-childe-nodes-existence, child_nodes, remove, get_all_child_nodes

--- 
### check if element has any child nodes in Javascript?
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

--- 
### get the all child nodes of an element
```html
<ul id="langs">
    <li>JavaScript</li>
    <li>Node</li>
    <li>Java</li>
    <li>Ruby</li>
    <li>Rust</li>
</ul>
```
* method 1 
```js 
const ul = document.querySelector('#langs');

// get all children
const childern = ul.childNodes;

// iterate over all child nodes
childern.forEach(li => {
    console.log(li.innerText);
});
```

* method 2: 
```js 
const children = ul.children;

// iterate over all child nodes
Array.from(children).forEach(li => {
    console.log(li.innerText);
});
```

---
### remove all the child nodes of a nodes
sol1:
```js 
// select the 1st child node
node.firstChild

function removeAllChildNodes(parent) {
    while (parent.firstChild) {
        parent.removeChild(parent.firstChild);
    }
}
``` 

--- 
#### sol2:
> Use jQuery
jQuery
```js 
$(selector).empty()
```

--- 
#### sol3:
> Use `node.remove()` method
```js
var node= document.getElementById("parent");
node.querySelectorAll('*').forEach(n => n.remove());
```

---
#### sol3:
The following code also removes all child nodes of a node:

```js
parent.innerHTML = '';
```
However, it is not recommended because it doesn’t remove the event handlers of the child nodes, which might cause a **memory leak**.