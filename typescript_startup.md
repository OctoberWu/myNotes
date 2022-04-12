### Create a new Typescript project
```sh
mkdir tsUI && cd $_
# 1. install yarn by npm
npm i yarn
yarn init -y
# 2. install express 
yarn add express@4.17.1 --dev
yarn add nodemon@2.0.15 --dev
yarn add typescript --dev
yarn add @types/express --dev
yarn add @types/node --dev
yarn add ts-node --dev
# 3. install typescript compiler 
tsc --init
# tsc index.ts
# 4. run typescript node ---
npx ts-node app.ts
```

#### to include javascript
```sh
# change allowJS in tsconfig.ts
compilerOptions: {
	allowJs: true
}
```


### Import / Export Typescript Syntax
```ts
// 合法的輸出語法
export var x = 42;                      // export a named variable
export function foo() {};               // export a named function

export default 42;                      // export the default export
export default function foo() {};       // export the default export as a function

export { encrypt };                     // export an existing variable
export { decrypt as dec };              // export a variable as a new name
export { encrypt as en } from 'crypto'; // export an export from another module
export * from 'crypto';                 // export all exports from another module

// 合法的輸入語法
import 'jquery';                        // import a module without any import bindings
import $ from 'jquery';                 // import the default export of a module
import { $ } from 'jquery';             // import a named export of a module
import { $ as jQuery } from 'jquery';   // import a named export to a different name
import * as crypto from 'crypto';    // import an entire module instance object
```