keywords: remove_event_listener, duplcated-bindings, customeized-modals

---
### remove_event_listener:
#### Remove all Event Listeners from an Element using JavaScript
```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
  </head>

  <body>
    <div id="box" style="background-color: salmon; width: 100px; height: 100px">
      Box 1
    </div>

    <script src="index.js"></script>
  </body>
</html>
```

```js
const box = document.getElementById('box');

// 👇️ add 2 event listeners
box.addEventListener('click', function handleClick() {
  console.log('box clicked first');
});

box.addEventListener('click', function handleClick() {
  console.log('box clicked second');
});

// ✅ Remove event listeners from Element
box.replaceWith(box.cloneNode(true));
```

#### references:
* [Remove all Event Listeners from an Element using JavaScript](https://bobbyhadz.com/blog/javascript-remove-all-event-listeners-from-element)


### customeized pop-up alert
```html
    <!-- Import agent conf file -->
    <div class="modal fade" id="upload-agent-conf-modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
      aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <h4 class="modal-title" id="myModalLabel">Choose import File</h4>
            <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span
                class="sr-only">Close</span></button>
          </div>
          <div class="modal-body">
            <input type="file" id="agent-conf-file-input" accept=".json">
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal">Cancel</button>
            <button type="button" class="btn btn-primary" onclick="importAgentFile();">Upload</button>
          </div>
        </div>
      </div>
    </div>
```

```js
  var btnGroupDiv = $('#settings-btns-group');
  var importBtn = document.createElement('button');
  importBtn.setAttribute('class', 'btn btn-info mx-1');
  importBtn.setAttribute('data-toggle', 'modal');
  importBtn.setAttribute('data-target', '#upload-agent-conf-modal');
  importBtn.innerHTML = `<i class="fas fa-file-import"></i> Import`;
  btnGroupDiv.append(importBtn);
  
  $('#upload-agent-conf-modal').modal('show');
  $('#upload-agent-conf-modal').modal('hide');
```