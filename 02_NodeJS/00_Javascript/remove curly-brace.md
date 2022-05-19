### If you want to remove all occurrences of { and } whether or not they are matched pairs, you can do it like this:

```js
var str = "{Street Name}, {City}, {Country}";
str = str.replace(/[{}]/g, "");
```