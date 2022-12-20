### js closest method not find sibling element?
`.closest()` method only traverses parents, not children.

---
### Add property to an array of objects
> `Use Array.prototype.map()`
```js
const userList = [
    {name: 'Joe Smith', age: 25},
    {name: 'Jennifer Smith', age: 20}
];
const modifiedUserList = userList.map(userObj => ({ ...userObj, status: 'active' }));
console.log(userList);
console.log(modifiedUserList);
```