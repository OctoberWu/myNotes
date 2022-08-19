keywords: remove-extensions

---

```js
// CANNOT accomodate 'test' and 'test.json' both cases
  _roleName = _roleName.split('.').slice(0, -1).join('.');

// CAN accomodate 'test' and 'test.json' both cases
  _roleName = _roleName.split('.').shift();
```