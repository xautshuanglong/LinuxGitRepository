/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 11:13:42
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 00:56:27
*  FilePath: /GoLearning/test_demo/test_multithread.go
*  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
)

func init() {
    fmt.Println("-------------------- test_multithread auto init() ------------------")
}

// 同一个包中不能有同名函数，重复定义
// func TestInit() {
//     fmt.Println("-------------------- test_multithread TestInit() ------------------")
// }

/********************************************************************\
*  description:
*  param {type}
*  return {type}
\********************************************************************/
func MultithreadInit() {
    fmt.Println("-------------------- test_multithread MultiThreadEntry --------------------")
}
