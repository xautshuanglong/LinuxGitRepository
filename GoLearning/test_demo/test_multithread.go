/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-06 11:13:42
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-12 20:04:46
*  FilePath: /GoLearning/test_demo/test_multithread.go
*  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
    "golang.org/x/sys/unix"
    "runtime"
    "strconv"
    "strings"
    "time"
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

// https://chai2010.cn/advanced-go-programming-book/
// 获取 goroutine id
func Getgoid() int64 {
    // panic("goid")
    var (
        buf [64]byte
        n   = runtime.Stack(buf[:], false)
        stk = strings.TrimPrefix(string(buf[:n]), "goroutine ")
    )

    idField := strings.Fields(stk)[0]
    id, err := strconv.Atoi(idField)
    if err != nil {
        panic(fmt.Errorf("can not get goroutine id: %v", err))
    }

    return int64(id)
}

func ThreadPrintTime(times int, threadName string) {
    for i := 0; i < times; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Printf("%02v %12v ---> current time: %v  pid:%v tid:%v goid:%v\n",
            i+1, threadName, time.Now().Format("2006-01-02 15:04:05.000"), unix.Getpid(), unix.Gettid(), Getgoid())
    }
}
