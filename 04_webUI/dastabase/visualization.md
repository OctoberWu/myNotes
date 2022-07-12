### 可視化Database的工具
* jQuery Builder. 
  * 用來組合不同查詢條件的工具
* calendar Builder

### Database transaction queries
```js
const numRemoveRows_ = 1000000; // default: remove oldest 1000000 rows. 
let logSqlCmd = `DELETE FROM syslog WHERE TIME IN (SELECT TIME FROM syslog ORDER BY TIME ASC LIMIT ${numRemoveRows_})`;
logDB.prepare(logSqlCmd).run();
logDB.prepare('VACUUM').run();
```