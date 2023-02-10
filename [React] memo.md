keywords: object-destructuring-assignment

---

### Object Destructuring Assignment
useState 這個方法是放在 React 物件裡面的一個方法，所以要使用它的時候，可以使用 React.useState，或者可以透過物件的解構賦值（object destructuring assignment）來取出 useState 這個方法：

/* useState 是在 React 物件中的一個方法，取用它的方法主要有兩種 */

```js
React.useState(); // 直接透過 `.` 來取用 React 物件內的方法
const { useState } = React; // 透過物件的解構賦值把 useState 方法取出
```

--- 
### useQuery
>The difference is the flow of data. useQuery is used to query async data, useMutation is used to mutate it. Or in the traditional CRUD speak:

```
Read: useQuery
Create/Update/Delete: useMutation
```


### useHistory
> Export 'useHistory' was not found in react-router-dom
```
* To solve the error "export 'useHistory' (imported as 'useHistory') was not found in 'react-router-dom'", use the useNavigate hook instead, e.g. const navigate = useNavigate(). The hook returns a function that lets you navigate programmatically.
* useLocation, with arguments
```

### Queueing a Series of State Updates 
reference: https://beta.reactjs.org/learn/queueing-a-series-of-state-updates
* batching: react batches state updates
> 當Component中，有多個setState()函數同時存在時，以最後一個為主。
> 當想要每個state的更新都被調用，則以函數形式傳入setState()中。


