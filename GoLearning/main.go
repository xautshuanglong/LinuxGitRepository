/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 14:52:47
 *  FilePath: /GoLearning/main.go
 *  Description:
\********************************************************************/
package main

import (
    "./demo"
    logutil "./util/log"
    "flag"
    "fmt"
    "github.com/Sirupsen/logrus"
    "os"
    // "strconv"
)

var cliName = flag.String("name", "nick", "Input your name")
var cliAge = flag.Int("age", 28, "Input Your Age")
var cliGender = flag.String("gender", "male", "Input Your Gender")

var cliFlag int

func init() {
    flag.IntVar(&cliFlag, "flagname", 1234, "Just for demo")
}

func main() {
    flag.Parse()
    // flag.Args() 函数返回没有被解析的命令行参数
    // flag.NArg() 函数返回没有被解析的命令行参数的个数
    // fmt.Printf("args=%s, num=%d\n", flag.Args(), flag.NArg())

    // 输出命令行参数
    // for index, arg := range os.Args {
    //     fmt.Println("Args["+strconv.Itoa(index)+"] = ", arg)
    // }

    logrus.Debug("test logrus tools")
    logrus.Trace("test logrus tools")
    logrus.Warn("test logrus tools")
    logrus.Info("test logrus tools")
    logrus.Error("test logrus tools")
    // logrus.Fatal("test logrus tools")
    // logrus.Panic("test logrus tools")

    demo.TestEntry()

    // 输出解析后的命令行参数
    logrus.WithFields(logrus.Fields{
        "name":     *cliName,
        "age":      *cliAge,
        "gender":   *cliGender,
        "flagname": cliFlag,
    }).Info("commandline arguments ---> ")

    testLog := &logrus.Logger{
        Out:       os.Stdout,
        Formatter: new(logutil.Formatter),
        Hooks:     make(logrus.LevelHooks),
        Level:     logrus.DebugLevel,
    }
    testLog.WithFields(logrus.Fields{
        "name": "custom formatter",
    }).Debug("test custom formatter ...")

    fmt.Println("========================= will exiting =========================")
}
