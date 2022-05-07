### check whether the directory exists
### check whether the file exists
### if not, copy the file the designate path
```js
const fs = require('fs')
function checkSettingsSync(_dir) {
  try {
    // --- directory is not created case ---
    if (!fs.existsSync(_dir)) {
      fs.mkdirSync(_dir);
      fs.copyFile('./settings.json', _dir + 'settings.json', (err) => {
        console.log(err);
      })
      return;
    }
    // --- settings file doesn't exit case ---
    if (!fs.existsSync(_dir + 'settings.json')) {
      fs.copyFile('./settings.json', _dir + 'settings.json', (err) => {
        console.log(err);
      })
      return;
    }
  } catch (err) {
    console.log(err)
  }
}
```

--- 
### how to check if objet is empty in js

* vanilla javascript version
- use `Object.keys`
```js
const empty = {};
Object.keys(empty).length === 0 && empty.constructor === Object;
```