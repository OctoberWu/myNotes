### Method 1: By Multer, Express
#### server side
```js
// ==============================
//     File Upload & Download 
// ==============================
const multer = require('multer');

const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    cb(null, licensePath);
  },

  filename: function (req, file, cb) {
    cb(null, file.originalname + '-' + Date.now())
  }
});
var upload = multer({ storage: storage });

router.post('/upload-license', upload.single('licenseFile'), (req, res, next) => {
  const file = req.file
  if (!file) {
    const error = new Error('Please upload a file')
    error.httpStatusCode = 400
    return next(error)
  }
  // res.send(file)
  license_state = 1;
  res.redirect('./settings2.html');
});
```
#### client-side
```html
	<form id="myFormId" action="/upload-license" enctype="multipart/form-data" accept=".lic" method="POST"> 
		<input type="file" name="licenseFile" />
		<input type="submit" value="Upload"/>
	</form>
```
--- 

### Method 2: By express-fileupload 
#### server-side
```js
// middleware
const fileUpload = require('express-fileupload');
const cors = require('cors');
app.use(fileUpload({
  createParentPath: true
}));
app.use(cors());

// client request
// router.post('/upload-license', async (req, res) => {
app.post('/upload-license', async (req, res) => {
  try {
    if (!req.files) {
      res.send({
        status: false,
        message: 'No file uploaded'
      });
    } else {
      let license = req.files.license;

      // --- move the uploaded file to designated directory ---
      license.mv(licensePath + license.name);

      // TODO: validate license
      license_state = 1;

      // --- send response ---
      res.send({
        status: true,
        message: 'File is uploaded'
      });
    }
  } catch (err) {
    res.status(500).send(err);
  }
});
```

#### client-side
```html
	<div class="row" >
		<div class="col-12">
			<div id="drop-area" style="display: none;">
				<form enctype="multipart/form-data" method="POST">
					<input type="file" name="fileElem"> 
					<button type="submit" role="button"> Upload File </button> 
				</form>
			</div>
		</div>
	</div>
```
```js
// --- upload file by XHR object ---
const url = "/upload-license";
const form = document.querySelector('form');

form.addEventListener('submit', e => {
  // disable default action
  e.preventDefault();

  // collect files
  const files = document.querySelector('[name=fileElem]').files;
  const formData = new FormData();
  formData.append('license', files[0]);
  console.log(files);

  // POST form data
  const xhr = new XMLHttpRequest();

  // log response
  xhr.onload = () => {
    console.log(xhr.responseText);
    res = JSON.parse(xhr.responseText);
    if (res.status) {
      $('.fa-medal').css('color', 'gold').prop('title', 'authorized license');
      promptBox('success', 'Authorized license');
    } else {
      $('.fa-medal').css('color', 'gray').prop('title', 'invalid license');
      promptBox('error', 'Invalid license');
    }
  }

  // create and send the request
  xhr.open('POST', url);
  xhr.send(formData);
});

```