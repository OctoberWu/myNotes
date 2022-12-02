keywords: JQuery

---
1. toggle Classes
```js
// JQuery 
  // let iconNode = $(this).parent().parent().find('.edit-cell-conn > i');
  // iconNode.toggleClass('fas fa-pen');
  // iconNode.toggleClass('fas fa-eye');

// Native Web-API
  let iconClasses = this.parentNode.parentNode.querySelector('.edit-cell-conn > i').classList;
  iconClasses.toggle('fa-pen'); 
  iconClasses.toggle('fa-eye'); 
```

2. get Closest Attribute
```js
// JQuery
  // let opt = $(data.element);
  // og = opt.closest('optgroup').attr('label');
  // $(data.element).attr('data-conn-cell', og + ', ' + data.text)
// Native Web-API
  let opt = data.element;
  og = opt.closest('optgroup').getAttribute('label');
  opt.setAttribute('data-conn-cell', og + ', ' + data.text);
```

3. select widget dataset with an event callback
```js
// e ---> Event
// JQuery
  let selVal = $(e.target).find(':selected');
  for (let opt of selVal) {
    let c = $(opt).data();
  };

// Native Web-API
  let selVal = e.target.selectedOptions;
  for (let opt of selVal) {
    let c = opt.dataset.connCell;
  }
```

4. remove the node itself
```js
// JQuery
  $('<selector>').remove();

// Native Web-API
  node.remove();
```