keywords: typescript-loader, webpack

--- 
### quick notes:
1. awesome-typescript-loader > ts-loader

>awesome-typescript-loader is no longer maintained and is not compatible with Webpack 5 (or with recent TypeScript versions). You'll need to remove awesome-typescript-loader, install ts-loader, and change the relevant block in webpack.config.dev.js to:

```json
	{
			test: /\.tsx?$/,
			loader: 'ts-loader',
			exclude: /node_modules/,
	},
```

#### reference: [Final loader didn't return a Buffer or String](https://stackoverflow.com/questions/67766617/error-final-loader-node-modules-awesome-typescript-loader-dist-entry-js-did)