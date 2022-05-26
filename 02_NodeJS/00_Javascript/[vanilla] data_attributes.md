keywords: data-attributes, stop-class-selectors

---
### quick note:

```js
// Good 
document.querySelector('[data-container]')
document.querySelector('[data-title]')

// Bad
document.querySelector('.container')
document.querySelector('.title')
```

```js
// Good
'[data-status="pending"]'
element.dataset.status = "pending"


// Bad
".pending:not(.active):not(.error)"
element.classList.remove("active")
element.classList.remove("error")
element.classList.add("pending")


```
