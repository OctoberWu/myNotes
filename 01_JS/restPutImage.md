### Save Selected Map

```js
function btnSaveSelectedMap() {
  // --- ensure the image scale is fit ---
  fCanvas.setZoom(1);
  console.log("------ submit Selected map ------");
  var map_data = fCanvas.toDataURL('png');
  var imgFilename = currSelectedMap_ + '.png';

  $.post('/map/image', {
    data: map_data,
    filename: imgFilename
  }, function (data, status) {
    console.log("--- map png post sent ---");
    console.log(`status: ${status}`);
    console.log(`data: ${data}`);
  })

  console.log("------ post Selected Map Yaml ------");

  yamlFilename = currSelectedMap_ + '.yaml';
  console.log(yamlFilename);

  $.get(`/map/info/${yamlFilename}`, function (data, status) {
    if (status === "success") {
      console.log("------ type of map data in yaml ------");
      console.log(`${data}`);

      $.post(`/map/info`, {
        content: data,
        filename: yamlFilename
      }, function () {
        console.log('post request return');
      });
    }
  });
}

```