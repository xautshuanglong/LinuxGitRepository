/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-22 20:26:23
 *  FilePath: /GoLearning/demo/test_multithread.go
 *  Description:
\********************************************************************/

package test_demo

import (
    "../os_api"
    "fmt"
    "github.com/Sirupsen/logrus"
    "runtime"
    "strconv"
    "strings"
    "sync"
    "sync/atomic"
    "time"
)

// func init() {
//     fmt.Println("-------------------- test_multithread auto init() ------------------")
// }

/********************************************************************\
 *  description:
 *  param {type}
 *  return {type}
\********************************************************************/
func Multithread_TestEntry() {
    // Multithread_Simple()
    // Multithread_Mutex()
    Multithread_Atomic()
}

// 多个线程孰先孰后没有定数
func Multithread_Simple() {
    go ThreadPrintTime(15, "subThread")
    ThreadPrintTime(15, "mainThread")
}

// 同一个包中不能有同名函数，重复定义
// func TestInit() {
//     fmt.Println("-------------------- test_multithread TestInit() ------------------")
// }

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
            i+1, threadName, time.Now().Format("2006-01-02 15:04:05.000"),
            os_api.GetCurrentProcessID(), os_api.GetCurrentThreadID(), Getgoid())
    }
}

func Multithread_Mutex() {
    var wg sync.WaitGroup
    wg.Add(5)
    go mutexWorker(&wg)
    go mutexWorker(&wg)
    go mutexWorker(&wg)
    go mutexWorker(&wg)
    go mutexWorker(&wg)
    wg.Wait()
    fmt.Printf("All go routine completed value: %d\n", total.value)
}

var total struct {
    sync.Mutex
    value int
}

func mutexWorker(wg *sync.WaitGroup) {
    defer wg.Done()

    var tempBefore, tempAfter int
    for i := 0; i <= 100; i++ {
        total.Lock()
        tempBefore = total.value
        total.value += i
        tempAfter = total.value
        logrus.Debugf("BeforValue:%v i:%v AfterValue:%v goid:%v", tempBefore, i, tempAfter, Getgoid())
        total.Unlock()
    }
}

func Multithread_Atomic() {
    var wg sync.WaitGroup
    wg.Add(5)
    go atomicWorker(&wg)
    go atomicWorker(&wg)
    go atomicWorker(&wg)
    go atomicWorker(&wg)
    go atomicWorker(&wg)
    wg.Wait()
    fmt.Printf("All go routine completed value: %d\n", totalValue)
}

var totalValue uint64

func atomicWorker(wg *sync.WaitGroup) {
    defer wg.Done()

    var tempBefore, tempAfter uint64
    var i uint64
    for i = 0; i <= 100; i++ {
        tempBefore = totalValue
        atomic.AddUint64(&totalValue, i)
        tempAfter = totalValue
        logrus.Debugf("BeforValue:%v i:%v AfterValue:%v goid:%v", tempBefore, i, tempAfter, Getgoid())
    }
}
