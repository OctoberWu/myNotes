keywords: docker-compose, tutorial,

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
