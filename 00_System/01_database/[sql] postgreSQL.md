keywords: postgresql, sql

--- 
### PostgreSQL Installation
#### Step 1 — Installing PostgreSQL 
```sh
sudo apt update
sudo apt install postgresql postgresql-contrib
## change password
sudo passwd postgres
## start the service
sudo systemctl start postgresql.service
```

#### Step 2 — Using PostgreSQL Roles and Databases
```sh
sudo -i -u postgres
psql

## to list all table, run the following
postgres=# \l

## to show the datatable, run the following
postgres=# \dt

## to exit out of the PostgreSQL prompt, run the following
postgres=# \q

## Another way to connect to the Postgres prompt is to run the psql command as the postgres account directly with sudo:
sudo -u postgres psql
```

#### Step 3 — Creating a New Role
```sh
## create a new role by running the following command
createuser --interactive
## If, instead, you prefer to use sudo for each command without switching from your normal account, run: 
sudo -u postgres createuser --interactive
```

#### Step 4 — Creating a New Database
```sh
## If you are logged in as the postgres account, you would type something like the following:
postgres@server:~$ createdb sammy
## alternative: bash way
sudo -u postgres createdb sammy
```

#### Step 5 — Opening a Postgres Prompt with the New Role
```sh
sudo adduser <username> 
## Once this new account is available, you can either switch over and connect to the database by running the following:
sudo -i -u <username>
## user name
sudo -u sammy psql
## If you want your user to connect to a different database, you can do so by specifying the database like the following: 
psql -d postgres
## Once logged in, you can get check your current connection information by running:
<username>=# \conninfo
### output
Output
You are connected to database "<username>" as user "<username>" via socket in "/var/run/postgresql" at port "5432".
```



### references:
  * [How To Install PostgreSQL on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-install-postgresql-on-ubuntu-20-04-quickstart)