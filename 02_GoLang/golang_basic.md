## Have you ever wondered what does parameters before the functions means.

```go
func (h handler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
    ...
}
```
It means ServeHTTP is not a standalone function. The parenthesis before the function name is the Go way of defining the object on which these functions will operate.

So, essentially ServeHTTP is a method of type handler and can be invoked using any object, say h, of type handler.
```go
h.ServeHTTP(w, r)
```

--- 
They are also called recievers. There are two ways of defining them. If you want to modify the receiver use a pointer like:
```go
func (s *MyStruct) pointerMethod() { } // method on pointer
```

--- 
If you dont need to modify the reciever you can define the reciever as a value like:
```go
func (s MyStruct) valueMethod() { } // method on value
```

--- 
Let's see the example below:
```go
package main

import "fmt"

type Mutatable struct {
    a int
    b int
}

func (m Mutatable) StayTheSame() {
    m.a = 5
    m.b = 7
}

func (m *Mutatable) Mutate() {
    m.a = 5
    m.b = 7
}

func main() {
    m := &Mutatable{0, 0}
    fmt.Println(m)
    m.StayTheSame()
    fmt.Println(m)
    m.Mutate()
    fmt.Println(m)
```

> The output of the above program is :
```
&{0 0}
&{0 0}
&{5 7}
```