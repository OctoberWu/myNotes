keywords: vscode, debugging

---
### lanuch.json file 
```json
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "Python: Current File",
			"type": "python",
			"request": "launch",
			// "program": "${file}", // 運行編輯器當前開啟的檔案 
			"program": "./modi_fleetConfigUI.py",
			"pythonPath": "/usr/bin/python3", // 使用python3進行運行
			"console": "integratedTerminal",
			"justMyCode": true
		}
	]
}
```

 