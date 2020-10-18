/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-18 20:26:42
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-18 20:30:46
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
