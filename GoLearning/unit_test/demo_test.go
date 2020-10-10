/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-10 16:33:17
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 16:55:48
*  FilePath: /GoLearning/unit_test/demo_test.go
*  Description:
\********************************************************************/
package test_demo

import (
    "fmt"
    "testing"
)

func MyFunction() {
    fmt.Println("-------------------- demo_test MyFunction --------------------")
}

func Test_MyFunction(t *testing.T) {
    fmt.Println("-------------------- demo_test Test_MyFunction --------------------")
    t.Log("testing.T.Log ...")
}
