1. chokidar
用於監看檔案或資料夾下的變化。

2. read-last-lines
讀最後一行的資料列。

3. more...


```js
const chokidar = require('chokidar');
const readLastLines = require('read-last-lines');

function errWatchDog() {
	try {
		var watchDog = chokidar.watch(logFile, { persistent: true });

		watchDog.on('change', async (filePath, stats) => {
			console.log(`[${new Date().toLocaleString()}] ${filePath} has been added.`);
			if (stats) {
				console.log('--- stats ---');
				console.log(stats);
				console.log('-------------');
				console.log(`File ${filePath} changed size to ${stats.size}`);
			}

			// var updateContent = await readLastLines.read(filePath, 1)
			// // console.log(updateContent);
			// var arrUpdated = updateContent.split(';');
			// // console.log(arrUpdated);
			// console.log(arrUpdated.length);
			// if (arrUpdated.length !== 8) {
			// 	console.log('Invalid Log Message Format!');
			// 	return;
			// }

			// let logSqlCmd = "INSERT INTO syslog (TIME, event_type, event_id, module_pub, module_sub, level, msg_cont, robot_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
			// logDB.prepare(logSqlCmd).run(arrUpdated);


			// let sqlCmd = "SELECT * FROM syslog ORDER BY TIME DESC LIMIT 1;";
			// let lastMsgRow = logDB.prepare(sqlCmd).all();
			// // console.log(lastMsgRow);

			// // --- forward message to line notifier ---
			// // lineNotifier.notify(updateContent);
			// // let arrMsg = JSON.parse(lastMsgRow)[0];
			// let arrMsg = lastMsgRow[0];
			// console.log(arrMsg);
			// let logMessage = arrMsg['TIME'] + '#' + arrMsg['event_type'] + '#' + arrMsg['event_id'] + '#' + arrMsg['module_pub'] + '#' + arrMsg['module_sub'] + arrMsg['level'] + '#' + arrMsg['msg_cont'] + '#' + arrMsg['robot_id'];
			// lineNotifier.notify(logMessage);

			// --- file size control ---
			var dbStats = fs.statSync(logFile);
			if (dbStats.size > limitFileSize_) {
				console.log('=== Reach file size limit! Reduce size method is triggered! ===');
				let logSqlCmd = `DELETE FROM syslog WHERE TIME IN (SELECT TIME FROM syslog ORDER BY TIME ASC LIMIT ${numRemoveRows_})`;
				logDB.prepare(logSqlCmd).run();
			}
		});
	} catch (error) {
		console.log(error);
	}
}

```

### issue: appearing error while using better-sqlite3 
SQLite Error: no such column:

當使用字串時，須使用單引號，替代雙引號。
```sql
SELECT * FROM (SELECT * FROM syslog LIMIT 367639,5) WHERE level IN ('INFO','WARN','ERROR') AND msg_cont LIKE '%%';
```