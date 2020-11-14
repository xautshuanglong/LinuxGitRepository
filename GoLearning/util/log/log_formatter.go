/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-14 22:55:00
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-14 22:58:02
 *  FilePath: /GoLearning/util/log/log_formatter.go
 *  Description:
\********************************************************************/

package log

import (
    "bytes"
    "github.com/Sirupsen/logrus"
    "time"
)

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
