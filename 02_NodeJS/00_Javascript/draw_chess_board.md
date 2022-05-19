### draw chess board on canvas
```js
function drawBoard(_ctx, _dim, _span = 50) {
  var bw = _dim.w;
  var bh = _dim.h;

  // --- vertical line ---
  for (var x = 0; x <= bw; x += _span) {
    _ctx.moveTo(0.5 + x, 0);
    _ctx.lineTo(0.5 + x, bh);
  }

  // --- horizontal line ---
  for (var y = 0; y <= bh; y += _span) {
    _ctx.moveTo(0, 0.5 + y);
    _ctx.lineTo(bw, 0.5 + y);
  }
  _ctx.strokeStyle = "transparent";
  _ctx.stroke();
}
```