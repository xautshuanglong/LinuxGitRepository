/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 11:13:42
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-09 01:17:41
*  FilePath: /GoLearning/test_demo/test_multithread.go
*  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
)

func init() {
    fmt.Println("-------------------- testing auto init() ------------------")
}

func TestInit() {
    fmt.Println("-------------------- testing TestInit() ------------------")
}

/********************************************************************\
*  description:
*  param {type}
*  return {type}
\********************************************************************/
func TestEntry() {
    fmt.Println("-------------------- testing TestEntry --------------------")
}
