keywords: typescript

---
### Build a typescript project
1. Conduct the command 
```sh
mkdir <project_name> && cd $_
npm init -y
# install typescript as dev. dependencies
npm i -D typescript
# install express and type definitions of node as dependencies
npm i -S express
npm i -D @types/express @types/node
```

1.1 create a tsconfig.json file
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

2. Write server code
`src/index.ts`
```typescript
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
