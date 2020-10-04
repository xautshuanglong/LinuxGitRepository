package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    for index, arg := range os.Args {
        fmt.Println("Args[" + strconv.Itoa(index) + "] = ", arg)
    }

    var argCount int = len(os.Args)
    if argCount > 2 {
        fmt.Println("Hello")
    } else {
        fmt.Println("World")
    }

    fmt.Printf("Hello, world!\n")
}

