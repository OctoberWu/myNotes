### generate the color code
```js
function getRGBA(r, g, b, a = 0.2) {

  r = parseInt(r * 255);
  g = parseInt(g * 255);
  b = parseInt(b * 255);

  return "rgba(" + r + "," + g + "," + b + "," + a + ")";
}
```