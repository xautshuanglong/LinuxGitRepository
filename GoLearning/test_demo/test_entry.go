/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-10 00:53:02
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 16:35:41
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

/********************************************************************\
*  description:
*  param {type}
*  return {type}
\********************************************************************/
func TestEntry() {
    Multithread_TestEntry()
    BaseType_TestEntry()
}
