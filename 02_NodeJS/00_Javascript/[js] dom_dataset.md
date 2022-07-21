keywords: dom, dataset attributes

---
### quick note:
#### Using dat attributes by Native APIs
```html
<!-- HTML Syntax -->
<article
  id="electric-cars"
  data-columns="3"
  data-index-number="12314"
  data-parent="cars">
</article>
```

```js
// JavaScript access
const article = document.querySelector('#electric-cars');
// The following would also work:
const article = document.getElementById("electric-cars")

article.dataset.columns // "3"
article.dataset.indexNumber // "12314"
article.dataset.parent // "cars"
```

```css 
/* attr() selectors*/
article::before {
  content: attr(data-parent);
}

/* attribute selectors */
article[data-columns='3'] {
  width: 400px;
}
article[data-columns='4'] {
  width: 600px;
}
```

#### Using dat attributes by Native JQuery
```js
$( "body" ).data( "foo", 52 );
$( "body" ).data( "bar", { isManual: true } );
$( "body" ).data( { baz: [ 1, 2, 3 ] } );
$( "body" ).data( "foo" ); // 52
$( "body" ).data(); // { foo: 52, bar: { isManual: true }, baz: [ 1, 2, 3 ] }
```

### base practices:
* get max/min value from a DOM
```javascript
  let valMin = $(this).attr('min');
  let valMax = $(this).attr('max');
```