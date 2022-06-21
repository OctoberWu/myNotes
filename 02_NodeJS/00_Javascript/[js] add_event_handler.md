keywords: event-handler

---
### quick note:
```html5
<button class="btn">Subscribe</button>
```
> element.addEventListener(type, addEventListener);

Solution 1:
```javascript
function clickHandler(event) {
   console.log('Button Clicked');
}
const btn = document.querySelector('.btn');
btn.addEventListener('click', clickHandler);
```

Solution 2: 
```javascript
const btn = document.querySelector('.btn');
btn.addEventListener('click', function(event){
   console.log('Button Clicked');
});
// or
btn.addEventListener('click', (event)=>{
   console.log('Button Clicked');
	 event.target // point to DOM element
});
```

Solution 3: 
> use bind() to implement