

* `light` needs to be reset to `null`, if the interval has been cleared. if the variable is controlled by another function feel free to change it back
```js
var light;

function change() {
    if (!light) {
        light = setInterval(disco,100);
    } else {
        clearInterval(light);
        light = null;
    }
}
```