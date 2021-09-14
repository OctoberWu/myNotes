### Draw Agents as Circles

```js
	// --- draw agent as a circle 
	ctx.beginPath();
	ctx.arc(pos.x, pos.y, 10, 0, 2 * Math.PI);
	ctx.fillStyle = 'orange'; // agent_color
	ctx.fill();
	ctx.stroke();
```