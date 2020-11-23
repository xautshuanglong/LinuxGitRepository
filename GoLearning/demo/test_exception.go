/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-23 14:41:54
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 23:00:39
 *  FilePath: /GoLearning/demo/test_exception.go
 *  Description:
\********************************************************************/

package demo

import (
    "fmt"
    "time"
)

type _CustomError struct {
    ErrorCode int
    ErrorMsg  string
    error
}

func (err _CustomError) Error() string {
    return fmt.Sprintf("ErrorCode:%d --> %s", err.ErrorCode, err.ErrorMsg)
}

func NewCustomError(code int, msg string) error {
    return &_CustomError{
        ErrorCode: code,
        ErrorMsg:  msg,
    }
}

func Exception_TestEntry() {
    // Exception_MapError()
    // Exception_RetriveError()
    // Exception_Panic()
    Exception_Recover()
    // Exception_PanicAndRecover()
}

func Exception_MapError() {
    mapValue := mapError()
    fmt.Println("map value :", mapValue)
}

func mapError() string {
    var m = map[string]string{}
    // m["key"] = "value"
    if v, ok := m["key"]; ok {
        return v
    }

    var a bool = true
    var b bool = false
    if c := a == b; a {
        fmt.Println("if line 1 ...  a,b,c =", a, b, c)
    }
    if c := a == b; b {
        fmt.Println("if line 2 ...  a,b,c =", a, b, c)
    }
    if c := a == b; c {
        fmt.Println("if line 3 ...  a,b,c =", a, b, c)
    }
    return "null"
}

func Exception_RetriveError() {
    value, err := getEvenNum(3)
    if err == nil {
        fmt.Println("Value =", value)
    } else {
        fmt.Println("getEvenNum failed!", err)
    }

    // test defer
    defer func() {
        fmt.Println("Call defer before return")
    }()
    value, err = getEvenNum(2) // 3 提前 return 第一个 defer 被调用
    if err != nil {
        fmt.Println("will return ... value:", value)
        return
    }
    defer func() {
        fmt.Println("Call defer after return")
    }()

    fmt.Println("getCustomError format testing:", getCustomError())

    err = retriveErrorOrNilIncorrect(true)
    if err == nil {
        fmt.Println("err==nil:", err)
    } else {
        fmt.Println("err!=nil:", err)
    }

    err = retriveErrorOrNilCorrect(false)
    if err == nil {
        fmt.Println("err==nil:", err)
    } else {
        fmt.Println("err!=nil:", err)
    }
}

func getEvenNum(num int) (int, error) {
    if num%2 == 0 {
        return num, nil
    }
    return 0, fmt.Errorf("the value %d is not even number", num)
}

func getCustomError() error {
    return NewCustomError(100, "this custom error strinig")
}

func retriveErrorOrNilIncorrect(nilFlag bool) error {
    var pError *_CustomError = nil // 是一个正常的错误（non-nil），错误的值是一个空指针。
    if !nilFlag {
        pError = &_CustomError{
            ErrorCode: 101,
            ErrorMsg:  "Custom error test",
        }
    }
    return pError
}

func retriveErrorOrNilCorrect(nilFlag bool) error {
    if !nilFlag {
        var pError *_CustomError = &_CustomError{
            ErrorCode: 101,
            ErrorMsg:  "Custom error test",
        }
        return pError
    }
    return nil // 此 nil 是错误或异常
}

func Exception_Panic() {
    defer fmt.Println("defer out of goroutine ...")
    var user = ""
    go func() {
        defer fmt.Println("defer caller ...")
        func() {
            defer func() {
                fmt.Println("defer here ...")
            }()
            if user == "" {
                panic("username should not be empty")
            }
        }()
    }()
    time.Sleep(1 * time.Second)
    fmt.Println("------------------ panic exit ----------------")
}

func Exception_Recover() {
    defer fmt.Println("defer out of goroutine ...")
    var user = ""
    go func() {
        defer func() {
            fmt.Println("defer caller ...")
            if err := recover(); err != nil {
                fmt.Println("recover success ...", err)
            }
        }()
        func() {
            defer func() {
                fmt.Println("defer here ...")
            }()

            if user == "" {
                panic("username should not be empty")
            }
            fmt.Println("after panic ...")
        }()
    }()

    time.Sleep(1 * time.Second)
    fmt.Println("------------------ panic exit ----------------")
}

func Exception_PanicAndRecover() {
}
