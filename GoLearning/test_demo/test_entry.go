/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-10 00:53:02
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 00:57:38
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

func TestInit() {
    fmt.Println("-------------------- test_entry TestInit() ------------------")
}

/********************************************************************\
*  description:
*  param {type}
*  return {type}
\********************************************************************/
func TestEntry() {
    fmt.Println("-------------------- test_entry TestEntry --------------------")
}
