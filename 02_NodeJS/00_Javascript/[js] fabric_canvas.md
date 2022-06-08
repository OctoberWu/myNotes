keywords: fabric, canvas
---
### quick note:
```js
// add grid on fabric.js canvas
function setMapResolution() {
  // 1. update on the map 
  var resVal = Number($('#resolution-value').val());
  console.log('----- res val ------');
  console.log(resVal);

  var canvasWidth = 600;
  var canvasHeight = 600;
  var grid = 1.0 / resVal;
  console.log(`grid: ${grid}`);
  gridCanvas.clear();
  for (var i = 0; i < (canvasWidth / grid); i++) {
    gridCanvas.add(new fabric.Line([i * grid, 0, i * grid, canvasHeight], { type: 'line', stroke: '#ccc', selectable: false }));
    gridCanvas.add(new fabric.Line([0, i * grid, canvasWidth, i * grid], { type: 'line', stroke: '#ccc', selectable: false }))
  }

}


//Set view of vis-network
// ------ view function test ------
function visSetFocus() {
  network2_.moveTo({
    position: { x: 0, y: 0 },
    scale: 2.0,
    // offset: { x: 150, y: 150 }
  })
}
```


``` html
// image editing tool
  <!-- <div id="map-tool" class="btn-group" style="display:none"> -->
    <!-- font size:
    <input type='text' id='font-size' min="0" max="150" style="width:3em" value='6'/> -->
    <!-- <button id='pen-draw' class="" alt="Pen"><i
        class="fas fa-pen"></i>&nbsp;Pen</button> -->
    <!-- <button id='line-draw' class="" alt="Line"><i
        class="fas fa-horizontal-rule"></i>&nbsp;Line</button>
    <button id='rect-draw' class="" alt="Rect"><i
        class="fal fa-rectangle-landscape"></i>&nbsp;Rect</button>
    <button id='erase-draw' class="" alt="Eraser"><i
        class="fas fa-eraser"></i>&nbsp;Eraser</button> -->
    <!-- <button id='undo-draw' class="" alt="Undo"><i
        class="fas fa-undo"></i>&nbsp;Undo</button> -->
    <!-- <button id='reset-zoom' class="" alt="Fit"><i
        class="fas fa-arrows-alt"></i>&nbsp;Fit</button>
    <button type="button" id="" onclick=""> Save </button> -->
  <!-- </div> -->
```

### notes:
將概念拆成小部份的功能組合，根據可行性以及合理性(依據實際的狀況跟可取得資源)結合成方案。

crop 成矩形，計算能符合畫面的區域，zoom in 到特定區域。

另外還有完整的流程的設計。
加入模擬所需的資料。