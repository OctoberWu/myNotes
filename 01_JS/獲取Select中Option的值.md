```html
<select id="myselect">
	<option value="1">Mr</option>
	<option value="2">Mrs</option>
	<option value="3">Ms</option>
	<option value="4">Dr</option>
	<option value="5">Prof</option>
</select>
```

### 獲取選項中的值
```js
$( "#myselect" ).val();
// => 1
```

### 獲取選項中的文字
```js
$( "#myselect option:selected" ).text();
// => "Mr"
```

###### tags: 'select', 'options'