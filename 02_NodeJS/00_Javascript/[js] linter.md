keywords: eslinter, lint, jquery-missing

---
### quick note:
ESLint dollar($) is not defined. (no-undef)
You are missing

```js
"env": {
  "browser": true,
  "commonjs": true,
  "es6": true,
  "jquery": true
},
```
> $ is not declared as a global without jquery environment enabled. Because of that, you are getting a no-undef error, saying that you are using variable that haven't been declared.