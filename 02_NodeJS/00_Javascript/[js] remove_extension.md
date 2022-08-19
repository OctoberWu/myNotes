keywords: remove-extensions, json-escape-character

---
### extension removal for filename
```js
// CANNOT accomodate 'test' and 'test.json' both cases
  _roleName = _roleName.split('.').slice(0, -1).join('.');

// CAN accomodate 'test' and 'test.json' both cases
  _roleName = _roleName.split('.').shift();
```

### JSON escape character
* For JSON, escape is special: '\\n'