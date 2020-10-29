/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-29 20:03:41
 *  FilePath: /GoLearning/main.go
 *  Description:
\********************************************************************/
package main

import (
    "./test_demo"
    "flag"
    "fmt"
    "github.com/Sirupsen/logrus"
    "io"
    "os"
    // "strconv"
)

var cliName = flag.String("name", "nick", "Input your name")
var cliAge = flag.Int("age", 28, "Input Your Age")
var cliGender = flag.String("gender", "male", "Input Your Gender")

var cliFlag int

func init() {
    flag.IntVar(&cliFlag, "flagname", 1234, "Just for demo")
    logrus.SetFormatter(&logrus.TextFormatter{
        FullTimestamp: true,
    }) // logrus.SetFormatter(&logrus.JSONFormatter{})
    logrus.SetReportCaller(true)
    logrus.SetLevel(logrus.InfoLevel)

    logFile, err := os.OpenFile("logrus.log", os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0666)
    if err == nil {
        logrus.SetOutput(io.MultiWriter(os.Stdout, logFile))
    } else {
        logrus.Info("Failed to open log file")
    }
}

func main() {
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
    logrus.Println("test logrus tools")
    logrus.WithFields(logrus.Fields{
        "test_key": "test_value",
        "xixi":     "haha",
    }).Info("fields testing")
}
