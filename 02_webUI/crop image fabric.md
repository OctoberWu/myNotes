
```js
// ======================
//      Crop Map 
// ======================

let fCanvas = new fabric.Canvas('c', {
  isDrawingMode: false,
  borderColor: 'gray'
});
// console.log(JSON.stringify(fCanvas));

// Define the URL where your background image is located
// Create a new instance of the Image class
var img_ = document.getElementById('initial-image');


// let selectionRect;
// let currentImage;
function addSelectRect() {
  selectionRect = new fabric.Rect({
    fill: "rgba(0,0,0,0.3)",
    originX: "left",
    originY: "top",
    stroke: "black",
    opacity: 1,
    width: fCanvas.width,
    height: fCanvas.height,
    hasRotatingPoint: false,
    transparentCorners: false,
    cornerColor: "white",
    cornerStrokeColor: "black",
    borderColor: "black",
    cornerSize: 12,
    padding: 0,
    cornerStyle: "circle",
    borderDashArray: [5, 5],
    borderScaleFactor: 1.3,
  });

  selectionRect.scaleToWidth(200);
  fCanvas.add(selectionRect)
  // set active object
  fCanvas.setActiveObject(selectionRect)
}

function showCropTool() {
  console.log(`--- show crop tool ---`);
  var btnCrop = document.createElement('crop-map');
  btnCrop.setAttribute("style", "display:none;");

  // create and add select rect
  addSelectRect();
  // render all 
  fCanvas.renderAll();
  // show crop button
  var btnCrop = document.getElementById('crop-map');
  btnCrop.removeAttribute('style');
}

function cropMap() {
  console.log(`--- crop map ---`);
  // create a mask rectangle for crop
  let rect = new fabric.Rect({
    left: selectionRect.left,
    top: selectionRect.top,
    width: selectionRect.getScaledWidth(),
    height: selectionRect.getScaledHeight(),
    absolutePositioned: true,
  })
  // add the current image clipPath property
  currentImage.clipPath = rect;
  // remove the mask layer
  fCanvas.remove(selectionRect);
  // init new image instance
  var cropped = new Image();
  // set src value of canvas cropped area as toDataURL
  cropped.src = fCanvas.toDataURL({
    left: rect.left,
    top: rect.top,
    width: rect.width,
    height: rect.height,
  });
  // after onload clear the canvas and add cropped image to the canvas
  cropped.onload = function () {
    fCanvas.clear();
    image = new fabric.Image(cropped);
    image.left = rect.left;
    image.top = rect.top;
    image.setCoords();
    fCanvas.add(image);
    fCanvas.renderAll();
  };
}

// When the image loads, set it as background image
img_.onload = function () {
  restGetSelectedMap_fb();
};

function restGetSelectedMap_fb() {
  var opt = document.getElementById('fileSelect').value;
  var myDataURL;

  // --- get the map meta-data ---
  console.log("------ post Selected Map Yaml ------");
  var yaml_filename = document.getElementById('fileSelect').value;

  yaml_filename = yaml_filename.split('.').slice(0, -1).join('.');
  yaml_filename += '.yaml';
  console.log(yaml_filename);

  $.get(`/map/info/${yaml_filename}`, function (data, status) {
    if (status === "success") {
      console.log("------ reset get select map 2 ------");
      // data = YAMLtoJSON(data);
      console.log(`${data}`);
      data = data.split(/\r?\n/);
      // data = data.pop();
      console.log(data);

      var map_res = 1.0;
      var map_org = "";
      for (i in data) {
        var el = data[i].split(':');
        var key = el[0];
        console.log(key);
        if (key === 'resolution') {
          console.log(`el[1]: ${el[1]}`);
          map_res = Number(el[1]);
          continue;
        }
        if (key === 'origin') {
          // console.log(`el[1]: ${el[1]}`);
          el[1] = el[1].replace(/[\[\]']+/g, '');
          var arrPos = el[1].split(',');
          var origin = {};
          origin.x = Number(arrPos[0]);
          origin.y = Number(arrPos[1]);
          origin.t = Number(arrPos[2]);

          // console.log(origin);
          map_org = el[1];
          continue;
        }

      }

      // reflect resolution value
      $('#resolution-value').val(map_res);

      // ------ build grid ------
      var canvasWidth = 600;
      var canvasHeight = 600;
      var grid = 1.0 / map_res;
      console.log(`data.resolution: ${data.resolution}`);
      console.log(`grid: ${grid}`);
      for (var i = 0; i < (canvasWidth / grid); i++) {
        gridCanvas.add(new fabric.Line([i * grid, 0, i * grid, canvasHeight], { type: 'line', stroke: '#ccc', selectable: false }));
        gridCanvas.add(new fabric.Line([0, i * grid, canvasWidth, i * grid], { type: 'line', stroke: '#ccc', selectable: false }))
      }
    }
  });

  // --- get the map image ---
  $.get(`/map/image/${opt}`, function (data, status) {
    if (status === "success") {
      console.log("------ type of map data ------");
      // console.log(typeof data);
      // console.log(data);
      myDataURL = `data:image/png;base64,${data.data}`;
      // console.log(`x: ${data.x}, y: ${data.y}`);
      // console.log(data);

      var img = new Image();
      img.onload = function () {
        // var dom = test.getBoundingClientRect();
        // console.log(dom);

        var f_img = new fabric.Image(img, { opacity: .8 });
        currentImage = f_img;
        // console.log(`width: ${data.w*.8}, height: ${data.h*.8}`);

        fCanvas.setWidth(600);
        fCanvas.setHeight(600);

        f_img.scaleToWidth(600);
        f_img.scaleToHeight(600);


        fCanvas.setBackgroundImage(f_img);
        fCanvas.renderAll();
      };
      img.src = myDataURL;
    }
  });

}

function restGetMapFilelist(_domID) {
  $.get("/maps", function (data, status) {
    if (status === "success") {
      $(`#${_domID}`).find('option').remove();
      data.forEach(function (filename) {
        $(`#${_domID}`).append(`<option value='${filename}'>${filename}</option>`);
      });
    }
  });
}
```