### What's docker.sock
`docker.sock` is the UNIX socket that Docker daemon is listening to. It's the main entry point for Docker API. It also can be TCP socket but by default for security reasons Docker defaults to use UNIX socket.

通過RESTful API  作為 Endpoint與 dockerd 互動

ref: 
* [docker.sock](https://docs.docker.com/engine/reference/commandline/dockerd/#examples)
* [Docker Tips : about /var/run/docker.sock](https://betterprogramming.pub/about-var-run-docker-sock-3bfd276e12fd)


### [Angular] Define