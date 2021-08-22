#### How to Use docker compose
**Install**
```console
$sudo apt install docker-compose
```
**When the error msgs occur**
[Docker command can't connect to Docker daemon](https://stackoverflow.com/questions/33562109/docker-command-cant-connect-to-docker-daemon)
**run the command**
```console
$sudo usermode -aG docker $(whoami) 
```

