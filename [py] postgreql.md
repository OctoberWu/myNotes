keywords: python, postgresql

---
### DB Operation Quick Start
1. Install `psycopg2`
```sh 
# option 1
pip install psycopg2
# option 2
yum install python-psycopg2
```
---
2. Connect Distributed
 2-1 建立連接獲得 connect 物件
 2-2 獲得遊標物件，一個遊標物件可以對資料庫進行執行操作，非執行緒安全，多個應用會在同一個連接種建立多個游標；
 2-3 書寫sql語句
 2-4 呼叫execute()方法執行sql
 2-5 抓取資料（可選操作）
 2-6 提交事物
 2-7 關閉連線
```python
import psycopg2
# 獲得連線
conn = psycopg2.connect(database="my_database", user="postgres", password="xxxxxx", host="127.0.0.1", port="5432")
# 獲得遊標物件
cursor = conn.cursor()
# sql語句
sql = "INSERT INTO my_shuju (id,name,age,role_id) VALUES (4,'z4', 50, 2);"
# 執行語句
cursor.execute(sql)
# conn.commit()
# 獲取單條資料.
# data = cursor.fetchone()
# 列印
# print("database version : %s " % data)
# 事物提交
conn.commit()
# 關閉資料庫連線
conn.close()
```

---
3. Create Table
```python
# -*- coding: utf-8 -*-
import psycopg2
# 獲得連線
conn = psycopg2.connect(database="python", user="postgres", password="123456", host="127.0.0.1", port="5432")
# 獲得遊標物件，一個遊標物件可以對資料庫進行執行操作
cursor = conn.cursor()
# sql語句 建表
sql = """CREATE TABLE student (
id serial4 PRIMARY KEY, 
num int4,
name varchar(25));"""
# 執行語句
cursor.execute(sql)
print("student table created successfully")
# 事物提交
conn.commit()
# 關閉資料庫連線
conn.close()
```
---
4. INSERT 
```python
#!/usr/bin/python

import psycopg2

conn = psycopg2.connect(database="testdb", user="postgres", password="pass123", host="127.0.0.1", port="5432")
print "Opened database successfully"

cur = conn.cursor()

cur.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (1, 'Paul', 32, 'California', 20000.00 )");

cur.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (2, 'Allen', 25, 'Texas', 15000.00 )");

cur.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (3, 'Teddy', 23, 'Norway', 20000.00 )");

cur.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 )");

conn.commit()
print "Records created successfully";
conn.close()
```

5. SELECT
* source 
```python
#!/usr/bin/python

import psycopg2

conn = psycopg2.connect(database="testdb", user="postgres", password="pass123", host="127.0.0.1", port="5432")
print "Opened database successfully"

cur = conn.cursor()

cur.execute("SELECT id, name, address, salary  from COMPANY")
rows = cur.fetchall()
for row in rows:
   print "ID = ", row[0]
   print "NAME = ", row[1]
   print "ADDRESS = ", row[2]
   print "SALARY = ", row[3], "\n"

print "Operation done successfully";
conn.close()
```
* output
```sh
Opened database successfully
ID =  1
NAME =  Paul
ADDRESS =  California
SALARY =  20000.0

ID =  2
NAME =  Allen
ADDRESS =  Texas
SALARY =  15000.0

ID =  3
NAME =  Teddy
ADDRESS =  Norway
SALARY =  20000.0

ID =  4
NAME =  Mark
ADDRESS =  Rich-Mond
SALARY =  65000.0

Operation done successfully
```

---
6. UPDATE
* source
```python
#!/usr/bin/python

import psycopg2

conn = psycopg2.connect(database="testdb", user="postgres", password="pass123", host="127.0.0.1", port="5432")
print "Opened database successfully"

cur = conn.cursor()

cur.execute("UPDATE COMPANY set SALARY = 25000.00 where ID=1")
conn.commit
print "Total number of rows updated :", cur.rowcount

cur.execute("SELECT id, name, address, salary  from COMPANY")
rows = cur.fetchall()
for row in rows:
   print "ID = ", row[0]
   print "NAME = ", row[1]
   print "ADDRESS = ", row[2]
   print "SALARY = ", row[3], "\n"

print "Operation done successfully";
conn.close()
```

* output
```sh 
Opened database successfully
Total number of rows updated : 1
ID =  1
NAME =  Paul
ADDRESS =  California
SALARY =  25000.0

ID =  2
NAME =  Allen
ADDRESS =  Texas
SALARY =  15000.0

ID =  3
NAME =  Teddy
ADDRESS =  Norway
SALARY =  20000.0

ID =  4
NAME =  Mark
ADDRESS =  Rich-Mond
SALARY =  65000.0

Operation done successfully
```
---
7. DELETE
* source 
```python 
#!/usr/bin/python

import psycopg2

conn = psycopg2.connect(database="testdb", user="postgres", password="pass123", host="127.0.0.1", port="5432")
print "Opened database successfully"

cur = conn.cursor()

cur.execute("DELETE from COMPANY where ID=2;")
conn.commit
print "Total number of rows deleted :", cur.rowcount

cur.execute("SELECT id, name, address, salary  from COMPANY")
rows = cur.fetchall()
for row in rows:
   print "ID = ", row[0]
   print "NAME = ", row[1]
   print "ADDRESS = ", row[2]
   print "SALARY = ", row[3], "\n"

print "Operation done successfully";
conn.close()
```

* output
```sh 
Opened database successfully
Total number of rows deleted : 1
ID =  1
NAME =  Paul
ADDRESS =  California
SALARY =  20000.0

ID =  3
NAME =  Teddy
ADDRESS =  Norway
SALARY =  20000.0

ID =  4
NAME =  Mark
ADDRESS =  Rich-Mond
SALARY =  65000.0

Operation done successfully
```

---
8. Error Handling
* source:
```python 
# -*- coding: utf-8 -*-
import psycopg2
# 獲得連線
conn = psycopg2.connect(database="python", user="postgres", password="123456", host="127.0.0.1", port="5432")
# 獲得遊標物件，一個遊標物件可以對資料庫進行執行操作
cursor = conn.cursor()
# sql語句 建表
sql ="""select * from test"""
params = (3,)
try:
    # 執行語句
    cursor.execute(sql,params)
except psycopg2.Error as e:
    print(e)
# 事物提交
conn.commit()
# 關閉資料庫連線
cursor.close()
conn.close()
```
* output
```sh 
Opened database successfully
Records created successfully
```