/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-18 20:26:42
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-18 20:30:14
 *  FilePath: /GoLearning/test_demo/test_entry.go
 *  Description:
\********************************************************************/
package test_demo

import (
    "fmt"
)

func init() {
    fmt.Println("-------------------- test_entry auto init() ------------------")
}

func TestEntry() {
    Multithread_TestEntry()
    BaseType_TestEntry()
}
