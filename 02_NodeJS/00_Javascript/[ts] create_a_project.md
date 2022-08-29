keywords: nodejs, typescript, express, restful, postgresql, redis, pm2, typeorm, node-best-practices

---
### Create a Typscript project
1. Starting a typescript project 
```sh
$mkdir <project_name> && cd $_
$npm init -y
# install typescript as dev. dependencies
$npm i -D typescript
# or
$npm i typescript --save-dev

# generate typescript configuration file
$npx tsc --init
## set the typescript compiling configuration
$vim tsconfig.json
```

1.1 tsconfig.json file reference
```json
{
  "compileOnSave": false,                     //編輯器在儲存檔案的時候根據tsconfig.json重新產生編譯檔案
  "compilerOptions": {
    /* 基本選項 */
    "target": "es6",                          // 指定編譯生成的JS版本: 'ES3' (default), 'ES5', 'ES6'/'ES2015', 'ES2016', 'ES2017', or 'ESNEXT'
    "module": "commonjs",                     // 指定生成哪種模組
    "outDir": "./build",                      // 指定輸出目錄
    "esModuleInterop": true,                  // 兼容模組導入的方式
    "module": "commonjs",                     // 指定生成哪種模組: 'commonjs', 'amd', 'system', 'umd' or 'es2015'
    "lib": [],                                // 編譯需要引入的特定函式庫檔案
    "allowJs": true,                          // 允許編譯 javascript 文件
    "checkJs": true,                          // 報告 javascript 文件中的錯誤
    "jsx": "preserve",                        // 指定 jsx 代碼的生成: 'preserve', 'react-native', or 'react'
    "declaration": true,                      // 生成相應的 '.d.ts' 文件
    "declarationMap": true,                   //生成宣告檔案的 sourceMap
    "sourceMap": true,                        // 生成相應的 '.map' 文件
    "outFile": "./",                          // 將輸出文件合併為一個文件
    "rootDir": "./",                          // 檔案應該要被放置的位置
    "composite": true,                        // 是否编译构建引用项目
    "tsBuildInfoFile": "./",                  // 指定文件存儲增量編譯信息，默認為 tsconfig.tsbuildinfo
    "removeComments": true,                   // 刪除編譯後的所有的註釋
    "noEmit": true,                           // 不產生輸出檔案
    "importHelpers": true,                    // 從 tslib 導入輔助工具函數
    "isolatedModules": true,                  // 將每個文件做為單獨的module（與 'ts.transpileModule' 類似）.

    /* 嚴格的類型檢查選項 */
    "strict": true,                           // 啟用所有嚴格類型檢查選項                    
    "noImplicitAny": true,                    // 在表達式和聲明上有隱含的 any類型時報錯                   
    "strictNullChecks": true,                 // 啟用嚴格的 null 檢查                  
    "strictFunctionTypes": true,              //啟用檢查function型別        
    "strictBindCallApply": true,              //啟用對 bind, call, apply 更嚴格的型別檢查           
    "strictPropertyInitialization": true,     //啟用class实例属性的賦值檢查
    "noImplicitThis": true,                   //當 this 表達式值為 any 類型的時候，生成一個錯誤                
    "alwaysStrict": true,                     // 以嚴格模式檢查每個module，並在每個文件裡加入 'use strict'                  

    /* 額外的檢查 */
    "noUnusedLocals": true,                   // 有未使用的變數時，拋出錯誤
    "noUnusedParameters": true,               // 有未使用的參數時，拋出錯誤
    "noImplicitReturns": true,                // 並不是所有function里的代碼都有返回值時，拋出錯誤
    "noFallthroughCasesInSwitch": true,       // 報告 switch 語句的 fallthrough 錯誤。 （即，不允許 switch 的 case 語句貫穿）
    "noUncheckedIndexedAccess": true,         //檢查 index signature 屬性是否是undefined     

    /* 模組選項 */
    "moduleResolution": "node",               // 選擇模組解析策略： 'node' (Node.js) or 'classic' (TypeScript pre-1.6)
    "baseUrl": "./",                          // 用於解析非相對模組名稱的基目錄
    "paths": {},                              // 模組名到基於 baseUrl 的路徑映射的列表
    "rootDirs": [],                           // 根文件夾列表，其組合內容表示項目運行時的結構內容
    "typeRoots": [],                          // 包含類型聲明的文件列表
    "types": [],                              // 需要包含的類型聲明文件名列表
    "allowSyntheticDefaultImports": true,     // 允許從沒有設置默認導出的模組中默認導入。

    /* Source Map Options */
    "sourceRoot": "./",                       // 指定調試器應該找到 TypeScript 文件而不是源文件的位置
    "mapRoot": "./",                          // 指定調試器應該找到映射文件而不是生成文件的位置
    "inlineSourceMap": true,                  // 生成單個 soucemaps 文件，而不是將 sourcemaps 生成不同的文件
    "inlineSources": true,                    // 將代碼與 sourcemaps 生成到一個文件中，要求同時設置了 --inlineSourceMap 或 --sourceMap 屬性

    /* 其他選項 */
    "experimentalDecorators": true,           // 啟用裝飾器
    "emitDecoratorMetadata": true,            // 為裝飾器提供元數據的支持
        
    /* 進階選項 */
    "skipLibCheck": true,                     //不會檢查引入的函式庫檔案
    "forceConsistentCasingInFileNames": true  // 確保檔案的大小寫一致
  },
  "include":[
      "src/**/*.ts"
  ],
  "exclude":[
      "node_modules"
  ]
}
```

`*` - 表示匹配0至多個字元(不包含分隔符號)
`?` - 匹配一個相符字元（不包含分隔符號）
`**/`- 表示匹配所有子資料夾

2. Compiling the Typescript Project
* typescript/index.tx
```ts
const world = 'world';

export function hello(who: string = world): string {
  return `Hello ${who}! `;
}
```
```sh
# primitive mode
$npx tsc
# to activate watch mode
$npx tsc -w 
```


3. Composing server code

* Dependencies Installation
```sh
# install express and type definitions of node as dependencies
npm i -S express
npm i -D @types/express @types/node
```

`src/index.ts`
```ts
import express, { Application } from "express";

const PORT = process.env.PORT || 8000;

const app: Application = express();

app.get("/ping", async (_req, res) => {
  res.send({
    message: "pong",
  });
});

app.listen(PORT, () => {
  console.log("Server is running on port", PORT);
});
```


### Create a new Typescript project
#### Pre-requisites
```sh
mkdir <project_name> && cd $_ 
```

* Method 1: yarn
```sh
# 1. project init by yarn
npm i yarn
yarn init -y
# 2. install express 
yarn add express@4.17.1 --dev
# 3. install packages
yarn add typescript --dev
yarn add @types/express --dev
yarn add @types/node --dev
yarn add ts-node --dev
yarn add nodemon@2.0.15 --dev

# --- configuration of system code ---
# 3. install typescript compiler 
tsc --init
# tsc index.ts
# 4. run typescript node ---
npx ts-node app.ts
```

* Method 2:  npm
```sh 
# 1. project init by npm
mkdir <project_name> && cd $_ 
npm i init -y
# 2. install express
npm i express
# 2-1. install typescript 
npm i -D typescript @types/express @types/node ts-node 
# 2-2. install test package 
npm i -D supertest @types/supertest @types/node jest @types/jest ts-jest

# --- configuration of system code ---
# 3. install typescript compiler 
npx tsc --init
#For our system we’re only going to adjust two options — “outDir” (where to put the compiled Javascript) and “rootDir” (where the source code lives):
"outDir": "./lib", 
"rootDir": "./src"
# tsc index.ts

# 4. run typescript node 
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



---
### Production ready Node.js REST API Setup using TypeScript, PostgreSQL and Redis

#### tech stack:
1. **TypeScript.** - with a strict mode. All types have to be explicitly specified.
2. **Express.** - The last version fully supports async/await, so no callback and no explicit promises in our routes/controllers.
3. **PostgreSQL.** This time a relational database. Let’s see how easy it’s to use.
4. **TypeORM** — powerful ORM written in TypeScript, supports migrations, Active Record, has an excellent query builder and much more.
5. **Winston** — A logger for just about everything :)
6. **Redis.** We will use this in-memory store for caching. It’s going to one extra line of code which makes a huge difference in performance.
7. **PM2.** — process manager for node.js apps, it includes clustering, load balancing, simple terminal monitoring, and log management.


### references:
  * [Production ready Node.js REST API Setup using TypeScript, PostgreSQL and Redis](https://itnext.io/production-ready-node-js-rest-apis-setup-using-typescript-postgresql-and-redis-a9525871407)
  * [alexpermiakov/node-rest-api](https://github.com/alexpermiakov/node-rest-api/)
	* [Node.js Best Practices](https://github.com/goldbergyoni/nodebestpractices#2-error-handling-practices)

