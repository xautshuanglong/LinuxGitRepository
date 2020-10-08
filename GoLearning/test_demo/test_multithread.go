/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 11:13:42
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-08 22:54:59
*  FilePath: /GoLearning/src/test_demo/test_multithread.go
*  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
)

func init() {
    fmt.Println("-------------------- testing init() ------------------")
}

func Init() {
    fmt.Println("-------------------- testing Init() 1 ------------------")
}

/********************************************************************\
*  description:
*  param {type}
*  return {type}
\********************************************************************/
func TestEntry() {
    fmt.Println("-------------------- testing TestEntry --------------------")
}
