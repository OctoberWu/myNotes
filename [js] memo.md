### js closest method not find sibling element?
`.closest()` method only traverses parents, not children.

---
### Add attributes to an array of objects (Immutable object)
> `Use Array.prototype.map()`
```js
const userList = [
    {name: 'Joe Smith', age: 25},
    {name: 'Jennifer Smith', age: 20}
];
const modifiedUserList = userList.map(userObj => ({ ...userObj, status: 'active' }));
```

### If you want to open link in a new tab:
```html
<a href="https://example.com" target="_blank">some text</a>
```