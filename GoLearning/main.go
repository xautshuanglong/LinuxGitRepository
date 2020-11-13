/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-13 14:35:39
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
    initLogUtil()
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

    test_demo.TestEntry()

    // 输出解析后的命令行参数
    logrus.WithFields(logrus.Fields{
        "name":     *cliName,
        "age":      *cliAge,
        "gender":   *cliGender,
        "flagname": cliFlag,
    }).Info("commandline arguments")
    fmt.Println("========================= will exiting =========================")
}

func initLogUtil() {
    var testHook = &Hook{
        HookName: "ShuanglongCustom",
        LogLevels: []logrus.Level{
            logrus.DebugLevel,
            logrus.InfoLevel,
        },
    }
    logrus.AddHook(testHook)
    logrus.SetFormatter(&logrus.TextFormatter{
        FullTimestamp: true,
        // ForceColors:   true,
    }) // logrus.SetFormatter(&logrus.JSONFormatter{})
    logrus.SetReportCaller(true)
    logrus.SetLevel(logrus.TraceLevel)

    var logFileOk = false
    var logDir = "./logs"
    var logFilename = "logrus.log"
    fileInfo, err := os.Stat(logDir)
    if os.IsNotExist(err) || fileInfo.Size() == 0 {
        err := os.Mkdir(logDir, os.ModePerm)
        if err != nil {
            logrus.SetOutput(os.Stdout)
            logrus.Printf("Mkdir failed: %v", err)
        } else {
            logFileOk = true
        }
    } else {
        logFileOk = true
    }
    if logFileOk {
        logFile, err := os.OpenFile(logDir+"/"+logFilename, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0666)
        if err == nil {
            logrus.SetOutput(io.MultiWriter(os.Stdout, logFile))
        } else {
            logrus.SetOutput(os.Stdout)
            logrus.Printf("Failed to open log file: %v", err)
        }
    }
}

type Hook struct {
    HookName  string
    LogLevels []logrus.Level
}

func (hook *Hook) Fire(entry *logrus.Entry) error {
    entry.Data["HookBy"] = hook.HookName
    return nil
}

func (hook *Hook) Levels() []logrus.Level {
    return hook.LogLevels
}
