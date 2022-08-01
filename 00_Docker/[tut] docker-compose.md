keywords: docker-compose, tutorial, psuedo-tty, tty-allocation

---
### docker run command
```sh
docker run -d \
--name mongodb \
-p 8080:8080 \
-e MONGO_INITDB_ROOT_USERNAME=admin \
-e MONGO_INITDB_ROOT_PASSWORD=password \
--net mongo-network \
mongo
```
### mongo-docker-compose.yaml
```yaml
version: '3'
services: 
	mongodb: <container_name>
		image: mongo
		ports:
			- 27017:27017
		environment:
			- MONGO_INITDB_ROOT_USERNAME=admin
			- MONGO_INITDB_ROOT_PASSWORD=password
```

---
### docker run command
```sh
docker run -d \
--name mongo-express \
-p 8080:8080 \
-e ME_CONFIG_MONGODB_ADMINUSERNAME=admin \
-e ME_CONFIG_MONGODB_ADMINPASSWORD=password \
-e ME_CONFIG_MONGODB_server=mongodb \
--net mongo-network \
mongo-express
```
### mongo-docker-compose.yaml
```yaml
version: '3'
services: 
	mongo-express:
		image: mongo-express
		ports:
			- 8080:8080
		environment:
			- ME_CONFIG_MONGODB_ADMINUSERNAME=admin
			- ME_CONFIG_MONGODB_ADMINPASSWORD=password
			- ME_CONFIG_MONGODB_SERVER=mongodb
```

---
### tty-alloction:
* 使用docker時，`-t` 用配置虛擬終端界面(psuedo tty) 
* 當使用 `docker-compose.yaml` 時
```yaml
version: '3'
services:
  myservice:
	  image: debian
		stdin_open: true  # docker run -i
		tty: true         # docker run -t
```

---
### Keep Your Docker Container Running for Debugging
* The easiest way to keep the container running is to change its entry point to a command that will continue running forever.
`tail -f /dev/null` 
```shell
docker run -d --name myc keeprun <ENTRY_POINT>
docker run -d --name myc keeprun tail -f /dev/null
```