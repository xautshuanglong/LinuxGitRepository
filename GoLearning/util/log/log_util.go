/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-14 22:43:15
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-16 10:15:59
 *  FilePath: /GoLearning/util/log/log_util.go
 *  Description:
\********************************************************************/
package log

import (
    "github.com/Sirupsen/logrus"
    nested "github.com/antonfisher/nested-logrus-formatter"
    "io"
    "os"
    "time"
)

func init() {
    var testHook = &Hook{
        HookName: "ShuanglongCustom",
        LogLevels: []logrus.Level{
            logrus.TraceLevel,
            logrus.DebugLevel,
            logrus.InfoLevel,
            logrus.WarnLevel,
            logrus.ErrorLevel,
            logrus.FatalLevel,
        },
    }
    logrus.AddHook(testHook)
    logrus.SetFormatter(&nested.Formatter{
        TimestampFormat: time.RFC3339,
        ShowFullLevel:   true,
    })
    // logrus.SetFormatter(&logrus.TextFormatter{
    //     FullTimestamp: true,
    //     // ForceColors:   true,
    // })
    logrus.SetLevel(logrus.TraceLevel)
    logrus.SetReportCaller(true)

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
