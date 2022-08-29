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
  "compilerOptions": {
    "target": "es6",
    "module": "commonjs",
    "outDir": "./build",
    "strict": true,
    "esModuleInterop": true
  }
}
```

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

