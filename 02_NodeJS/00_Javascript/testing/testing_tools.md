keywords: testing, test-cafe

---

### TestCafe

#### tutorial video:
* [Test Automation](https://testautomationu.applitools.com/testcafe-tutorial/chapter7.7.html)

#### tutorial repo:
* [moatazeldebsy/TestCafe-TAU ](https://github.com/moatazeldebsy/TestCafe-TAU)


#### Write some testing cases by `testcafe`  (https://github.com/DevExpress/testcafe)

### testcafe reflections:
1. use debug() 
```js
await t.debug()
```

2. To check the existence of the DOM element 
3. When the DOM element is overlapped, use `dispatchEvent()`
```js
const target = Selector(`#delete-flow-${randomName}`);
await t
	.click('#flow-back')
	.setNativeDialogHandler(() => true)
	.dispatchEvent(target, 'click')
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ alternative event dispatchment
	.wait(1000)
	.expect(Selector(`#flowbar-${randomName}`).exists).notOk({ message: 'Flow still exist!' });
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DOM existence check
```

### testcafe
* command line:
```sh
# switch to nodejs:16
$nvm use 16
# run testcafe in command line
$testcafe "chrome '--window-size=1920,1080'" e2e/01_Dashboard_flow.test.js --skip-js-errors
```

* `.testcaferc.json`
```json
{
	"browsers": [
		{
			"path": "chrome",
			"command": "--window-size=1920,1080"
		}
	],
	"src": [
		"e2e/01_Dashboard_flow.test.js"
	],
	"skipJsErrors": true,
	"baseUrl": "http://localhost:3000",
	"speed": 1,
	"concurrency": 1,
	"selectorTimeout": 3000,
	"assertionTimeout": 3000
}
```

### testcafe configurations sample
```json
{
  "browsers": ["chrome"], // 使用 chrome 瀏覽器測試
  "speed": 1,             // 測試執行速度
  "concurrency": 1,       // 1 (最快) ~ 0.01 (最慢)
  "src": ["tests"],       // 要跑的測試程式碼
  "reporter": [           // 同時產生 spec 和 json 格式測試報告
    {
      "name": "spec"
    },
    {
      "name": "json",
      "output": "reports/report.json"
    }
  ],
  "screenshotPath": "reports/screenshots", // 截圖存放的位置
  "takeScreenshotsOnFails": true,          // 測試失敗時自動截圖
  "videoPath": "reports/videos",           // 測試錄影的位置
  "videoOptions": {                        // 錄影設定
    "singleFile": false,                   // 每個測試的錄影檔案都分開
    "failedOnly": false                    // 每個測試都錄影
  },
  "selectorTimeout": 3000,                 // 尋找網頁元素的 timeout 時間 3 秒
  "assertionTimeout": 3000                 // 判定預期結果的 timeout 時間 3 秒
}
```
