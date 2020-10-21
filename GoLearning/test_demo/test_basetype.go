/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-18 20:26:42
 *  LastEditor: xautshuanglong
 *  LastEditTime: ,: 2020-10-21 17:59:54
 *  FilePath: ,: \GoLearning\test_demo\test_basetype.go
 *  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
)

func BaseType_TestEntry() {
    fmt.Println("========================= BaseType_TestEntry =========================")
    BaseType_Slice()
    BaseType_Rename()
}

func BaseType_Slice() {
    fmt.Println("------------------------ BaseType_Slice ------------------------")

    var makeSlice = make([]int, 3, 5)
    printSlice(makeSlice)

    var nilSlice []int
    printSlice(nilSlice)
    /* 创建切片 */
    numbers := []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
    printSlice(numbers)

    /* 打印原始切片 */
    fmt.Println("numbers ==", numbers)

    /* 打印子切片从索引1(包含) 到索引4(不包含)*/
    fmt.Println("numbers[1:4] ==", numbers[1:4])

    /* 默认下限为 0*/
    fmt.Println("numbers[:3] ==", numbers[:3])

    /* 默认上限为 len(s)*/
    fmt.Println("numbers[4:] ==", numbers[4:])

    numbers1 := make([]int, 0, 5)
    printSlice(numbers1)

    /* 打印子切片从索引 0(包含) 到索引 2(不包含) */
    number2 := numbers[:2]
    printSlice(number2)

    /* 打印子切片从索引 2(包含) 到索引 5(不包含) */
    number3 := numbers[2:5]
    printSlice(number3)

}

func printSlice(x []int) {
    fmt.Printf("len=%d cap=%d slice=%v\n", len(x), cap(x), x)
}

func BaseType_Rename() {
    fmt.Println("------------------------ BaseType_Rename ------------------------")

    type TestType []int
    var i TestType
    var t []int

    printSlice(t)

    // i = append(i, 1, 2, 3)
    // t = append(t, 1, 2, 3)
    t = i

    printSlice(i)
    printSlice(t)

    type IntType int
    var a IntType
    var b int
    // a = b // https://www.coder.work/article/212328 https://golang.org/ref/spec#Assignability

    fmt.Println(a, b)
}
