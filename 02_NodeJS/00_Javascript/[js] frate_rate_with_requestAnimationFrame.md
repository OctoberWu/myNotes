keywords: requestAnimationFrame

---
##  Controlling the Frame Rate with requestAnimationFrame
Limiting the frame rate while using requestAnimationFrame can be a common want especially when coding Games where you want your animations and mechanics to not exceed a particular mark of frames per second. Let’s go through 2 ways of doing it.

### Quick and Easy Way
Using setTimeout inside the rAF method is an easy way.

```js
var fps = 30;
 
function draw() {
    setTimeout(function() {
        requestAnimationFrame(draw);
 
        // ... Code for Drawing the Frame ...
 
    }, 1000 / fps);
}
 
draw();
```
Nothing too fancy, simple enough!

## Better Refined Approach

Ok, browsers cannot optimize setTimeout or setInterval. So it’s kinda better to do our own calculations and restrict the frame rate. Let’s see how.

```js
var fps = 30;
var now;
var then = Date.now();
var interval = 1000/fps;
var delta;
  
function draw() {
     
    requestAnimationFrame(draw);
     
    now = Date.now();
    delta = now - then;
     
    if (delta > interval) {
        // update time stuffs
         
        // Just `then = now` is not enough.
        // Lets say we set fps at 10 which means
        // each frame must take 100ms
        // Now frame executes in 16ms (60fps) so
        // the loop iterates 7 times (16*7 = 112ms) until
        // delta > interval === true
        // Eventually this lowers down the FPS as
        // 112*10 = 1120ms (NOT 1000ms).
        // So we have to get rid of that extra 12ms
        // by subtracting delta (112) % interval (100).
        // Hope that makes sense.
         
        then = now - (delta % interval);
         
        // ... Code for Drawing the Frame ...
    }
}
 
draw();
```

Very simple code. All we do is set our frames per second and intervals between each frame. In the drawing function we deduct our last frame’s execution time from the current time to check whether the time elapsed since the last frame is more than our interval (which is based on the fps) or not. If the condition evaluates to true, we set the time for our current frame which is going to be the “last frame execution time” in the next drawing call.

Eventually all our drawing code is executed.