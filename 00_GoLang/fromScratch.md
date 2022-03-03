### go module 使用 kingpin

* get the module
```sh
$ go get gopkg.in/alecthomas/kingpin.v2
```

* example
```go
package main

import (
  "fmt"
  "gopkg.in/alecthomas/kingpin.v2"
)

var (
  debug   = kingpin.Flag("debug", "Enable debug mode.").Bool()
  timeout = kingpin.Flag("timeout", "Timeout waiting for ping.").Default("5s").Envar("PING_TIMEOUT").Short('t').Duration()
  ip      = kingpin.Arg("ip", "IP address to ping.").Required().IP()
  count   = kingpin.Arg("count", "Number of packets to send").Int()
)

func main() {
  kingpin.Version("0.0.1")
  kingpin.Parse()
  fmt.Printf("Would ping: %s with timeout %s and count %d\n", *ip, *timeout, *count)
}
```


---
### 解決出現以下錯誤訊息

Case: 初次在 VS Code 建立GO 專案
> go module init

```sh
go.mod file not found in current directory or any parent directory； see ‘go help modules‘
```

初始化Go Module, 在專案目錄下，在命令行中以下命令。
```sh
## init go module
$ go mod init <PROJECT_NAME>

## build go binary
$ go build
```

--- 

### GOPATH
When using modules, GOPATH is no longer used for resolving imports. However, it is still used to store downloaded source code (in GOPATH/pkg/mod) and compiled commands (in GOPATH/bin).

---
Reference: https://hoohoo.top/blog/go-module-and-go-get-common-parameter-descriptions/