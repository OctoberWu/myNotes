keywords: export, sqlite, csv

---
### export sqlite database to CSV file

Quick start:

```sh 
# enter command line mode
sqlite3 your_db_name

# select data from the books table and export it to the selected_data.csv file. 
sqlite> .headers on
sqlite> .mode csv
sqlite> .output selected_data.csv
sqlite> SELECT book_id,
 ...> title,
 ...> authors,
 ...> year
 ...> FROM books;
sqlite> .quit

# use the options of the sqlite3 tool to export data from the SQLite database to a CSV file.
# ex. 1 
sqlite3 -header -csv your_database_name "select * from books;" > books.csv
# ex. 2 
sqlite3 -header -csv your_database_name "select * from books where year = 2017;" > books_2017.csv
# ex. 3 
sqlite3 -header -csv your_database_name "select * from books where year = 2017 and authors = 'J. K. Rowling';" > JKRowling_books_2017.csv


```

references:
* [Export SQLite Database to a CSV file using sqlite3 command line tool](https://deeplearning.lipingyang.org/export-sqlite-database-to-a-csv-file-using-sqlite3-command-line-tool-ubuntu-16-04/)


--- 
### sqlite3 in more advance
references:
* [SQLite 學習筆記之三 - 交易](http://garyliutw.blogspot.com/2013/07/sqlite_24.html)