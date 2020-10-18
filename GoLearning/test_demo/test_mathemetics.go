/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-10 00:44:37
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 00:51:44
*  FilePath: /GoLearning/test_demo/test_mathemetics.go
*  Description:
\********************************************************************/
package test_demo

import (
    "fmt"
)

func init() {
    fmt.Println("-------------------- test_mathemetics auto init() ------------------")
}

// 同一个包中不能有同名函数，重复定义
// func TestInit() {
//     fmt.Println("-------------------- test_mathemetics TestInit() ------------------")
// }
