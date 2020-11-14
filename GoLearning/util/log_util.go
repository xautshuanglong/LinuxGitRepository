/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-14 22:43:15
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-14 22:49:02
 *  FilePath: /GoLearning/util/log_util.go
 *  Description:
\********************************************************************/
package util

import (
    "bytes"
    "github.com/Sirupsen/logrus"
    "io"
    "os"
    "time"
)

func init() {
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

type Formatter struct {
    FormatterName string
}

func (format *Formatter) Format(entry *logrus.Entry) ([]byte, error) {
    timeFormatter := time.RFC3339
    buffer := &bytes.Buffer{}
    buffer.WriteString(entry.Time.Format(timeFormatter))
    buffer.WriteString(" [" + entry.Level.String() + "]")
    buffer.WriteString(" " + entry.Message)
    buffer.WriteByte('\n')
    return buffer.Bytes(), nil
}
