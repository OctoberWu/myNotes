keywords: delete oldest records rows from database

If you use an auto-increment field, you can easily write this to delete the oldest 100 records:

```sql
DELETE FROM mytable WHERE id IN (SELECT id FROM mytable ORDER BY id ASC LIMIT 100)
Or, if no such field is present, use ROWID:

DELETE FROM mytable WHERE ROWID IN (SELECT ROWID FROM mytable ORDER BY ROWID ASC LIMIT 100)
```
Or, to leave only the latest 1000 records:

```sql 
DELETE FROM mytable WHERE ROWID IN (SELECT ROWID FROM mytable ORDER BY ROWID DESC LIMIT -1 OFFSET 1000)
```