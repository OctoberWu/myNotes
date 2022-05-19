### Javascript Binding this 

#### The data-toggle value could be reached by 2 ways

```js
$('#realtime .btn').click(function () {
	var toggleState = this.getAttribute('data-toggle');  // Native
	// var toggleState = $(this).data('toggle');         // JQuery
	if (!toggleState) { return; }

	rtTrigger = (toggleState === 'on') ? 'on' : 'off';
	update();
})
```