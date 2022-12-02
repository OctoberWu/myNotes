keywords: object-destructuring-assignment

---

### Object Destructuring Assignment
useState 這個方法是放在 React 物件裡面的一個方法，所以要使用它的時候，可以使用 React.useState，或者可以透過物件的解構賦值（object destructuring assignment）來取出 useState 這個方法：

/* useState 是在 React 物件中的一個方法，取用它的方法主要有兩種 */

```js
React.useState(); // 直接透過 `.` 來取用 React 物件內的方法
const { useState } = React; // 透過物件的解構賦值把 useState 方法取出
```