### `of` and `in` within For-Loop
```js
// of 取到的是值(value, object)
for (let obj of _pieChart) {
	arrStates[obj.mode] = obj.number;
}

// in 取到的是參考(index, reference)
for (let i in _pieChart) {
	arrStates[i] = _pieChart[i];
}
```