keywords: '`req.body` undefined', body-parser, swagger-restful-api

---
### quick note:
#### debugging messge
```shell
req.body is undefined
```

* Using swagger api, WITH CAN NOT get the POST/PUT body. It's because the body-parser module of express middle aren't imported properly

```js
var bodyParser = require('body-parser')
app.use( bodyParser.json() );       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
})); 
```

---
### quick note:
![How to access POST form fields in Express](https://stackoverflow.com/questions/5710358/how-to-access-post-form-fields-in-express)



