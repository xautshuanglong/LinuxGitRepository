/********************************************************************\
*  Author: xautshuanglong
*  Date: 2020-10-10 16:33:17
*  LastEditor: xautshuanglong
*  LastEditTime: 2020-10-10 18:21:17
*  FilePath: /GoLearning/unit_test/demo_test.go
*  Description:
\********************************************************************/
package test_demo

import (
    "sync"
    "testing"
)

// ----------------------------------------------------------------------------------------

func Fibonacci(n int) int {
    if n < 2 {
        return n
    }
    return Fibonacci(n-1) + Fibonacci(n-2)
}

func Test_Fibonacci(t *testing.T) {
    var n, expected = 7, 13
    var actual = Fibonacci(n)
    if actual != expected {
        t.Errorf("Fib(%d) = %d; expected %d", n, actual, expected)
    }

    var testCases = []struct {
        n        int // input n
        expected int // expected result
    }{
        {1, 1},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 5},
        {6, 8},
        {7, 13},
        {8, 20},
    }
    for _, testCase := range testCases {
        actual = Fibonacci(testCase.n)
        if actual != testCase.expected {
            t.Errorf("Fib(%d) = %d; expected %d", testCase.n, actual, testCase.expected)
        }
    }
}

// ----------------------------------------------------------------------------------------
var (
    data   = make(map[string]string)
    locker sync.RWMutex
)

func WriteToMap(k, v string) {
    locker.Lock()
    defer locker.Unlock()
    data[k] = v
}

func ReadFromMap(k string) string {
    locker.RLock()
    defer locker.RUnlock()
    return data[k]
}

var pairs = []struct {
    k string
    v string
}{
    {"polaris", " 徐新华 "},
    {"studygolang", "Go 语言中文网 "},
    {"stdlib", "Go 语言标准库 "},
    {"polaris1", " 徐新华 1"},
    {"studygolang1", "Go 语言中文网 1"},
    {"stdlib1", "Go 语言标准库 1"},
    {"polaris2", " 徐新华 2"},
    {"studygolang2", "Go 语言中文网 2"},
    {"stdlib2", "Go 语言标准库 2"},
    {"polaris3", " 徐新华 3"},
    {"studygolang3", "Go 语言中文网 3"},
    {"stdlib3", "Go 语言标准库 3"},
    {"polaris4", " 徐新华 4"},
    {"studygolang4", "Go 语言中文网 4"},
    {"stdlib4", "Go 语言标准库 4"},
}

// 注意 TestWriteToMap 需要在 TestReadFromMap 之前
func Test_WriteToMap(t *testing.T) {
    t.Parallel()
    for _, tt := range pairs {
        WriteToMap(tt.k, tt.v)
    }
}

func Test_ReadFromMap(t *testing.T) {
    t.Parallel()
    for _, tt := range pairs {
        actual := ReadFromMap(tt.k)
        if actual != tt.v {
            t.Errorf("the value of key(%s) is %s, expected: %s", tt.k, actual, tt.v)
        }
    }
}
