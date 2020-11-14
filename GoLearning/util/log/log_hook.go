/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-14 22:55:15
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-14 22:58:21
 *  FilePath: /GoLearning/util/log/log_hook.go
 *  Description:
\********************************************************************/

package log

import (
    "github.com/Sirupsen/logrus"
)

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
