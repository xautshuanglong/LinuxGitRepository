/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-29 17:19:51
 *  FilePath: \GoLearning\test_demo\test_mathemetics.go
 *  Description:
\********************************************************************/

package test_demo

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
