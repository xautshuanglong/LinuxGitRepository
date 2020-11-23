/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-23 14:41:54
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 14:54:39
 *  FilePath: /GoLearning/demo/test_exception.go
 *  Description:
\********************************************************************/

package demo

import (
    "fmt"
)

func Exception_TestEntry() {
    Exception_MapError()
}

func Exception_MapError() {
    mapValue := mapError()
    fmt.Println("map value :", mapValue)
}

func mapError() string {
    var m map[string]string
    if v, ok := m["key"]; ok {
        return v
    }
    return ""
}
