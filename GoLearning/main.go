/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 15:36:02
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-11 22:52:37
*  FilePath: /GoLearning/main.go
*  Description:
\********************************************************************/
package main

import (
    "./test_demo"
    "flag"
    "fmt"
    "os"
    "strconv"
)

var cliName = flag.String("name", "nick", "Input your name")
var cliAge = flag.Int("age", 28, "Input Your Age")
var cliGender = flag.String("gender", "male", "Input Your Gender")

var cliFlag int

func Init() {
    flag.IntVar(&cliFlag, "flagname", 1234, "Just for demo")
}

func main() {
    Init()
    flag.Parse()
    // flag.Args() 函数返回没有被解析的命令行参数
    // func NArg() 函数返回没有被解析的命令行参数的个数
    fmt.Printf("args=%s, num=%d\n", flag.Args(), flag.NArg())
    for i := 0; i != flag.NArg(); i++ {
        fmt.Printf("arg[%d]=%s\n", i, flag.Arg(i))
    }

    // 输出命令行参数
    fmt.Println("name=", *cliName)
    fmt.Println("age=", *cliAge)
    fmt.Println("gender=", *cliGender)
    fmt.Println("flagname=", cliFlag)

    for index, arg := range os.Args {
        fmt.Println("Args["+strconv.Itoa(index)+"] = ", arg)
    }

    test_demo.TestInit()
    test_demo.TestEntry()
    test_demo.MathInit()
    test_demo.MultithreadInit()

    go test_demo.ThreadPrintTime(5, "subThread")
    test_demo.ThreadPrintTime(5, "mainThread")

    fmt.Println("-------------------- will exiting --------------------")
}
