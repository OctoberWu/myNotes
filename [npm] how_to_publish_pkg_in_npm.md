### How to publish the package in npm?

Step0: Go to https://www.npmjs.con/
 * create a new account 

--- 
Step1: Create and Publish Public packages
```sh 
mkdir pub-npm-test && cd $_
npm init -y
```

---
Step2: Add proper info in package.json
 * Git repo
 * Description
 * Entry point 
 * Keywords 
 * License

 --- 
 Step3: 
 * Create an index.js file
 ```js 
 console.log("my 1st npm pkg");
 ```

 * Create a symbolic link
> Executing npm link the command creates a symbolic link for your current package inside the global npm node_modules folder (The same folder where our global npm dependencies get installed).
```sh 
mkdir test-pkg
cd test-pkg 
npm init -y
# link created package
npm link pub-npm-test
```
* Inside the `test-pkg`, create a new file with the name `index.js` and add the following code inside it:
```js 
require("publish-npm-test")
```
* New, execute the index.js file
```sh
node index.js
```

---
Step4: Publish/Unpublish to the npm repo
* chech the user is login
```sh
npm whoami
npm login
npm publish
```

* navigate to your profile in npmjs.com and check the published pakcages

* Unpublish
```sh
npm unpublish <package>@<version>
npm unpublish pub-npm-test@1.0.0
```


#### Reference:
[How to publish the package in npm](https://medium.com/dhiwise/how-to-publish-the-package-in-npm-80b7a9b97a4c)