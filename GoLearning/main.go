/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 15:36:02
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 00:58:05
*  FilePath: /GoLearning/main.go
*  Description:
\********************************************************************/
package main

import (
    "fmt"
    "os"
    "strconv"
)
import "./test_demo"

func main() {
    for index, arg := range os.Args {
        fmt.Println("Args["+strconv.Itoa(index)+"] = ", arg)
    }

    var argCount int = len(os.Args)
    if argCount > 2 {
        fmt.Println("Hello")
    } else {
        fmt.Println("World")
    }

    fmt.Printf("Hello, world!\n")

    test_demo.TestInit()
    test_demo.TestEntry()
    test_demo.MathInit()
    test_demo.MultithreadInit()
}
