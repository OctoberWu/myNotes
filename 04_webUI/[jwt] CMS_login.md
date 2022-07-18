keywords: jwt, login-system, validtor, authentication, authorization, role-based

---
### quick note: 
* npm have a format validator, ajv. - JSON schema validator. handy

### axios Examples:
```js
  // --- request payload ---
  let payload = { camUUID: req.body.camUUID, enable: req.body.enable };
  // ------ axios method 1 ------

  let camRes = await axios.post(`http://${camIP}:${camPORT}/nxPlugin/activePlugin`, payload);
 // ------ axios method 2 ------
  let myRes = await axios({
    method: 'POST',
    url: `http://${camIP}:${camPORT}/nxPlugin/activePlugin`,
    data: payload
  }).then((response) => {
    return response;
  }).catch((err) => {
    console.error(err);
  })

  console.log(myRes.status);     // 200
  console.log(myRes.statusTest); // 'OK'
  console.log(myRes.data);       // response body in JSON format
	console.log(myRes.ok)          // [x] Note: different from `fetch` method, axios response does not contain ok property
```


### references:
* [Application config with YAML and JSON Schema validation](https://medium.com/trabe/application-config-with-yaml-and-json-schema-validation-94a870855314)
* [Day 19 - 二周目 - 帳密認証與JWT (JSON Web Token)傳遞](https://ithelp.ithome.com.tw/articles/10203292)
* [[筆記] 透過 JWT 實作驗證機制](https://medium.com/%E9%BA%A5%E5%85%8B%E7%9A%84%E5%8D%8A%E8%B7%AF%E5%87%BA%E5%AE%B6%E7%AD%86%E8%A8%98/%E7%AD%86%E8%A8%98-%E9%80%8F%E9%81%8E-jwt-%E5%AF%A6%E4%BD%9C%E9%A9%97%E8%AD%89%E6%A9%9F%E5%88%B6-2e64d72594f8)
* [Handling Authentication and Authorization with Node](https://medium.com/quick-code/handling-authentication-and-authorization-with-node-7f9548fedde8)
* [How to Authenticate Users and Implement CORS in Node.js Apps](https://www.freecodecamp.org/news/how-to-authenticate-users-and-implement-cors-in-nodejs-applications/)
* [How to Build an Authentication API with JWT Token in Node.js](https://www.section.io/engineering-education/how-to-build-authentication-api-with-jwt-token-in-nodejs/)
* [Using JWT (JSON Web Tokens) to authorize users and protect API routes](https://medium.com/@maison.moa/using-jwt-json-web-tokens-to-authorize-users-and-protect-api-routes-3e04a1453c3e)
* [HTTPS Authorized Certs with Node.js](https://engineering.circle.com/https-authorized-certs-with-node-js-315e548354a2)

#### tutorial and examples
* [JWT tutorial: In-depth Introduction to JSON Web Token](https://www.bezkoder.com/jwt-json-web-token/)
* [Node.js JWT Authentication with PostgreSQL example](https://www.bezkoder.com/node-js-jwt-authentication-postgresql/)
* [jwt-project](https://github.com/Olanetsoft/jwt-project)
* [onury/accesscontrol](https://github.com/onury/accesscontrol)

#### RABC references
* [The Fundamentals of Role-Based Access Control](https://www.bettercloud.com/monitor/the-fundamentals-of-role-based-access-control/)
* [How to use AccessControl for RBAC and ABAC in Node.js](https://blog.logrocket.com/using-accesscontrol-for-rbac-and-abac-in-node-js/)
* [Implement Access Control in Node.js](https://blog.nodeswat.com/implement-access-control-in-node-js-8567e7b484d1)
* [Implementing Role based Authorization using JSON Web Token in Node.JS](https://medium.com/@sanju.nitt/implementing-role-based-authorization-using-json-web-token-in-node-js-cdc3a96ecb5c)
* [Implementing Role-Based Access Control in a Node.js application](https://soshace.com/implementing-role-based-access-control-in-a-node-js-application/)
* [Authenticate Users With Node ExpressJS and Passport.js](https://heynode.com/tutorial/authenticate-users-node-expressjs-and-passportjs/)
* [Authentication Using Passport.js in a Node.js Backend API](https://javascript.plainenglish.io/authentication-using-passport-js-in-a-node-js-backend-api-51e9946549cb)
* [Using Passport for authentication in Node.js](https://blog.logrocket.com/using-passport-authentication-node-js/)
* [How to restrict access using Passport.js role-based authorisation](https://www.developerhandbook.com/passport.js/passport-role-based-authorisation-authentication/)
* [Adding Authorization to a Node.js App – Beyond Role-Based Access Control (RBAC)](https://www.osohq.com/post/adding-authorization-nodejs-app-beyond-role-based-access-control) * [How to implement dynamic Role-based Access Control (RBAC) in Express JS REST API.](https://dev.to/richienabuk/how-to-implement-dynamic-role-based-access-control-rbac-in-express-js-rest-api-54fe)
* [[week 17] 後端中階 - Express 實戰：簡易會員註冊系統 & 留言板](https://hackmd.io/@Heidi-Liu/note-be201-express-practice)

#### Micro-service - JWT
* [Securing Microservices with JWT](https://medium.com/ballerina-techblog/securing-microservices-with-jwt-a16b738b110f)