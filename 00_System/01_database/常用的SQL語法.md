A ∪ B   Set union: Combine two sets into one

A ∩ B   Set intersection: The members that A and B have in common

A − B   Set difference: The members of A that are not in B

These have direct counterparts in SQL:

A ∪ B : UNION or UNION ALL (UNION eliminates duplicates, UNION ALL keeps them)

A ∩ B : INTERSECT

A − B : EXCEPT

---
select datetime((strftime('%s', timestamp) / 5) * 5, 'unixepoch') interval,
       count(*) number
from FlowState
group by interval
order by interval

---
SELECT
  ROUND((JULIANDAY(strftime('%Y-%m-%d %H-%M-%S','now'))) -JULIANDAY(timestamp) ) as diff
FROM FlowState;

---
SELECT strftime('%Y-%m-%d %H:%M:%S', 'now');

SELECT strftime('%Y-%m-%d %H:%M:%S', 'now', '+8 hours');

2022-03-09 18:14:39

Select Cast ((
    JulianDay('2022-03-09 18:15:40') - JulianDay('2022-03-09 18:14:39')
) * 24 * 60*60 As Integer)
FROM FlowState;

---
SELECT julianday('now') - julianday(DateCreated) FROM Payment;

---
SELECT (julianday('now','+8 hours')- julianday(ts) )*24*60*60 diff FROM FlowState;

---
SELECT ROUND((julianday('now','+8 hours')- julianday(ts) )*24*60*60) diff FROM FlowState;

---
SELECT Round((julianday('now','+8 hours')- julianday(ts) )*24*60*60) AS diff FROM FlowState;

---
select interval,
       Round((julianday('now','+8 hours')- julianday(interval) )*24*60*60) AS diff,
       number
from (
select datetime((strftime('%s', ts) / 5) * 5, 'unixepoch') as interval,
       count(*) number
from FlowState
group by interval
order by interval
)
-

SELECT ROUND((JULIANDAY('now','+8 hours')- JULIANDAY(interval) )*86400) AS diff,
  number
FROM (
SELECT datetime((strftime('%s', ts) / 5) * 5, 'unixepoch') AS interval,
    count(*) number
FROM FlowState
GROUP BY interval)
ORDER BY diff

---
SELECT DISTINCT currId
FROM tableA 
WHERE currId Not IN 
    (SELECT DISTINCT nextId FROM tableB)
    
---
* update the state of the oldest row in flow state row 

UPDATE FlowState
SET state = 2
ORDER BY ts 
LIMIT 1;
    
---
UPDATE FlowState SET progress = progress + 10 where state=1 

---
UPDATE FlowState SET state=2 where state=1 ORDER BY ts LIMIT 1

---
Example 1 (for all rows):

UPDATE product SET price = price + 50
Example 2 (for a specific row):

UPDATE product SET price = price + 50 WHERE id = 1
Example 3 (for specific rows):

UPDATE product SET price = price + 50 WHERE id IN [1, 2, 3]
Example 4 (generic):

UPDATE {table} SET {column} = {column} + {value} WHERE {condition}
Where:

{table} - table name
{column} - column name
{value} - a number by which column's value should be increased or decreased
{condition} - some condition if any

---
select flow_id, state, progress from FlowState
where state <> 2 limit 10

---
include
SELECT * FROM syslog WHERE msg_cont LIKE '%EVENT NOT VALID%'
exclude
SELECT * FROM syslog WHERE msg_cont NOT LIKE '%EVENT NOT VALID%'

SELECT * FROM syslog WHERE (level="ERROR" OR level="lv1")

SELECT * FROM syslog  LIMIT 365000, 365317 WHERE (SELECT * WHERE level="ERROR")

SELECT * FROM (SELECT * FROM syslog LIMIT 365000, 2) WHERE level="ERROR"

---
INSERT OR REPLACE INTO FlowState (ts, flow_id, flow_name, state, progress, fleet_name, last_updated) VALUES ('2022-03-15 14:44:37', '25d1ca32-751a-4585-8969-77722562cba5', 'rack_to_rack', 1, 1, 'AUO', '2022-03-15 14:44:37');

### To supercharge SQL query - subquery
[SQL Subqueries](https://www.mssqltips.com/sqlservertip/6036/sql-server-subquery-example/)
--- 
