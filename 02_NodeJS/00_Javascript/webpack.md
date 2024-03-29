### Start to use webpack
```sh
# create a folder and change directory to it.
mkdir myPackBundlerTrial && cd $_
# create a new nodejs project
npm init -y
# install lodash module
npm install lodash
# install webpack module
npm install --save-dev webpack webpack-cli
# run webpack 
npm run build
# install css style
npm install --save-dev css-loader style-loader sass-loader
# install jest 
npm install --save-dev jest
```

### webpack config file 
```json
const path = require('path');

module.exports={
    entry: {
        index: './src/index.js'
    },
    output: {
        filename: 'awesome.js',
        path: path.resolve(__dirname, 'dist'),
    },
    module: {
        rules: [
            {
                test: /\.scss$/,
                use: [
                    'style-loader',
                    'css-loader',
                    'sass-loader',
                ]
            },
        ],
    }
};
```

### jest config template
```json
module.exports = {
    "roots": [
        "<rootDir>/tests/"
    ],
}
```

### webpack-dev-server 3.0 / 4.0 difference
* webpack.config.js 
  * contentBase -> static
```js
// webpack 3.0
module.exports = {
  devServer: {
    contentBase: path.join(__dirname, 'dist'),
  //^^^^^^^^^^^
    compress: true,
    port: 1257
  },
};


// webpack 4.0
module.exports = {
  devServer: {
    static: path.join(__dirname, 'dist'),
  //^^^^^^
    compress: true,
    port: 1257
  },
};

```