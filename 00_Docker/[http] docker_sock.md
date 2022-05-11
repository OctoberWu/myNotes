### What's docker.sock
`docker.sock` is the UNIX socket that Docker daemon is listening to. It's the main entry point for Docker API. It also can be TCP socket but by default for security reasons Docker defaults to use UNIX socket.

通過RESTful API  作為 Endpoint與 dockerd 互動

---
### with `-H` argument
You can configure the Docker daemon to listen to multiple sockets at the same time using multiple -H options:

The example below runs the daemon listenin on the default unix socket, and on 2 specific IP addresses on this host:
```sh
sudo dockerd -H unix:///var/run/docker.sock -H tcp://192.168.59.106 -H tcp://10.10.10.2
```

# references: 
* [docker.sock](https://docs.docker.com/engine/reference/commandline/dockerd/#examples)
* [Docker Tips : about /var/run/docker.sock](https://betterprogramming.pub/about-var-run-docker-sock-3bfd276e12fd)

