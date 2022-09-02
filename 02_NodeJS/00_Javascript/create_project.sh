You can convert any image into a favicon.ico file here: https://www.favicon-generator.org/

my-webpack-app
├── README.md
├── node_modules
├── package.json
├── .gitignore
├── public
│   ├── favicon.ico
├── src
│   ├── index.css
│   ├── index.js
├── webpack.config.js
├── index.html
├── server.js


mkdir my-webpack-app && cd my-webpack-app && touch README.md && npm init && git init && touch .gitignore && mkdir public && mkdir src && touch src/index.css && touch src/index.js && touch webpack.config.js && touch index.html && touch server.js

### .gitignore template
node_modules
npm-debug.log

### index.html template
<!-- index.html -->
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Sample Webpack App</title>
  </head>
  <body>
<script src="/bundle.js"></script>
  </body>
</html>
