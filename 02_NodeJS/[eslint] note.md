keywords: eslinter

---
### quick note:
* `npx eslint` use the local node_modules eslint, need to check the version, or `env` and `ecmaVesrion` may not be matched.
> current eslint version: 7.32.0

* prorities:
	- .eslintrc.js
	- .eslintrc.json

#### ISSUE: ESLint出现Environment key "es2021" is unknown
* `parserOptions: eslinter` 版本必須在7.0以上，才支援
* [](https://www.jianshu.com/p/9e96a00ff438)

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

---
### eslint quick note:
1. check all *.s files in a folder?
```sh 
$eslint --fix './server/*.js'
$eslint --fix './server/**/*.js'
```

---
### 使用eslint
1. 安裝eslint 
```sh 
$npm install -g eslint 
# =>
$eslint --fix './server/*.js'
```

2. 直接使用npx
> 使用npx是調用local node_modules中的eslint。eslint也有global的，不過就是global的`.eslintrc`
```sh 
$npx eslint --fix './server.js/
```

### references:
* [Configuring ESLint](https://eslint.org/docs/6.0.0/user-guide/configuring)
* [[JS] 使用 ESLint 提高程式碼品質](https://larrylu.blog/improve-code-quality-using-eslint-742cf1f384f1)
* [JS in Pipeline (5): Testing, Linting, and Git Hooks](https://medium.com/@jeanycyang/js-in-pipeline-5-testing-linting-and-git-hooks-f11108816611)
* [ESLint configuration](https://www.getcodeflow.com/eslint-configuration.html)