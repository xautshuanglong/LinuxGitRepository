/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-23 14:41:54
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 19:19:38
 *  FilePath: /GoLearning/demo/test_exception.go
 *  Description:
\********************************************************************/

package demo

import (
    "errors"
    "fmt"
)

type _CustomError struct {
    ErrorCode int
    ErrorMsg  string
    error
}

func (err *_CustomError) Error() string {
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
    Exception_RetriveError()
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
        fmt.Println("will return ...")
        return
    }
    defer func() {
        fmt.Println("Call defer after return")
    }()

    fmt.Println("getCustomError testing:", getCustomError())
}

func getEvenNum(num int) (int, error) {
    if num%2 == 0 {
        return num, nil
    }
    return 0, errors.New(fmt.Sprintf("the value %d is not even number", num))
}

func getCustomError() error {
    return NewCustomError(100, fmt.Sprintf("this custom error strinig"))
}
