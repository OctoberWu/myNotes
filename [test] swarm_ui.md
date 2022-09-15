keywords: swarm_core_ui-e2e-test

--- 
### quick notes:

* syntax substitutions
> bootstrap `CardWidget` is simply hide the wide, it still could be reached by selector
```js
// remove the widget from DOM tree
	$(this).remove();
// hide the widget, but still in the DOM tree
	$(this).CardWidget('remove');
```