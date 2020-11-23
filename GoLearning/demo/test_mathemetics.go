/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 14:49:10
 *  FilePath: /GoLearning/demo/test_mathemetics.go
 *  Description:
\********************************************************************/

package demo

import (
    "fmt"
)

func Init() {
    fmt.Println("-------------------- test_mathemetics auto init() ------------------")
}

// 同一个包中不能有同名函数，重复定义
// func TestInit() {
//     fmt.Println("-------------------- test_mathemetics TestInit() ------------------")
// }
