/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-18 20:26:42
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-18 20:33:49
 *  FilePath: /GoLearning/main.go
 *  Description:
\********************************************************************/
package main

import (
    "./test_demo"
    "flag"
    "fmt"
    // "os"
    // "strconv"
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
    // flag.NArg() 函数返回没有被解析的命令行参数的个数
    fmt.Printf("args=%s, num=%d\n", flag.Args(), flag.NArg())

    // 输出解析后的命令行参数
    fmt.Println("name=", *cliName)
    fmt.Println("age=", *cliAge)
    fmt.Println("gender=", *cliGender)
    fmt.Println("flagname=", cliFlag)

    // 输出命令行参数
    // for index, arg := range os.Args {
    //     fmt.Println("Args["+strconv.Itoa(index)+"] = ", arg)
    // }

    test_demo.TestEntry()

    fmt.Println("========================= will exiting =========================")
}
