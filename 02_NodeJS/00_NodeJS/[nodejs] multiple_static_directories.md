keywords: multiple-static-directories, express

---
### Setting up two different static directories in node.js Express framework
```javascript
app.use("/public", express.static(__dirname + "/public"));
app.use("/public2", express.static(__dirname + "/public2"));
```

* Serves files from the local directory public while:
```url
http://your.server.com/public/*
```

* Serves files from the local directory public2.
```url
http://your.server.com/public2/*
```