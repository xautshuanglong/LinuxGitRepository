/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 14:51:29
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-22 19:16:51
 *  FilePath: /GoLearning/demo/test_basetype.go
 *  Description:
\********************************************************************/

package test_demo

import (
    "fmt"
    "image/color"
    "reflect"
    "unicode/utf8"
    "unsafe"
)

func BaseType_TestEntry() {
    // BaseType_Array()
    // BaseType_String()
    // BaseType_Slice()
    // BaseType_Map()
    // BaseType_Rename()
    // BaseType_Inherit()
    // BaseType_Interface()
}

func BaseType_Array() {
    var a [3]int
    var b = [...]int{1, 2, 3}
    var c = [...]int{2: 3, 1: 2}
    var d = [...]int{1, 2, 4: 5, 6}

    fmt.Printf("len=%d cap=%d value=%v\n", len(a), cap(a), a) // len=3 cap=3 value=[0 0 0]
    fmt.Printf("len=%d cap=%d value=%v\n", len(b), cap(b), b) // len=3 cap=3 value=[1 2 3]
    fmt.Printf("len=%d cap=%d value=%v\n", len(c), cap(c), c) // len=3 cap=3 value=[0 2 3]
    fmt.Printf("len=%d cap=%d value=%v\n", len(d), cap(d), d) // len=6 cap=6 value=[1 2 0 0 5 6]

    var original = [...]int{1, 2, 3}
    fmt.Printf("original = %v\n", original)

    // 数组拷贝
    var copy1 = original // 原数组拷贝
    copy1[1] = 5         // 不改变原数组
    fmt.Printf("original=%v  copy1=%v len(copy1)=%v\n", original, copy1, len(copy1))

    // 数组指针
    var copy2 = &original // 指向原数组的指针
    copy2[1] = 7          // 修改原数组的值
    fmt.Printf("original=%v  copy2=%v len(copy2)=%v\n", original, copy2, len(copy2))

    // 数组遍历方法
    for i, v := range original {
        fmt.Printf("original[%v] = %v\n", i, v)
    }
    for i := range copy2 {
        fmt.Printf("copy2[%d] = %d\n", i, copy2[i])
    }
    for i := 0; i < len(original); i++ {
        fmt.Printf("original[%d] = %d\n", i, original[i])
    }

    // 二维数组
    var dimension_2 [5][5]int
    for i := range dimension_2 {
        fmt.Printf("dimension_2[%d] = %v\n", i, dimension_2[i])
    }

    // 长度为零的数组
    var e [0]int
    var f = [0]int{}
    var g = [...]int{}
    fmt.Printf("len=%d cap=%d value=%v\n", len(e), cap(e), e)
    fmt.Printf("len=%d cap=%d value=%v\n", len(f), cap(f), f)
    fmt.Printf("len=%d cap=%d value=%v\n", len(g), cap(g), g)
}

func BaseType_String() {
    fmt.Println("------------------------ BaseType_String ------------------------")

    var data = [...]byte{
        'h', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!',
    }
    fmt.Printf("data=%v  len=%v\n", data, len(data))
    str := "hello, world!"
    fmt.Printf("str=%v  len=%v\n", str, len(str))
    str1 := str[:5]
    fmt.Printf("str1=%s  len=%v\n", str1, len(str1))
    str2 := str[7:12]
    fmt.Printf("str2=%s  len=%v\n", str2, len(str2))

    fmt.Printf("len(str)=%v\n", (*reflect.StringHeader)(unsafe.Pointer(&str)).Len)
    fmt.Printf("len(str1)=%v\n", (*reflect.StringHeader)(unsafe.Pointer(&str1)).Len)
    fmt.Printf("len(str2)=%v\n", (*reflect.StringHeader)(unsafe.Pointer(&str2)).Len)

    bytes := []byte("Hello, 世界")
    fmt.Printf("bytes=%#v\n", bytes)
    fmt.Println("\"\\xe4\\xb8\\x96\\xe7\\x95\\x8c\" = ", "\xe4\xb8\x96\xe7\x95\x8c")
    for i, c := range bytes {
        fmt.Printf("bytes[%d]=%v\n", i, c)
    }
    for i, c := range "\xe4\xb8\x96\xe7\x95\x8c" {
        fmt.Printf("const_bytes[%d]=%v (%s)\n", i, c, string(c))
    }
    fmt.Printf("rune_test=%#v\n", []rune("世界"))             // []int32{19990, 30028}
    fmt.Printf("rune_test=%#v\n", string([]rune{'世', '界'})) // 世界

    // for range string 模拟实现
    utf8String := "hello, 世界!"
    forOnString(utf8String, func(i int, r rune) {
        fmt.Printf("simulate range utf8String[%d] = %v\n", i, r)
    })

    // []byte(string) 模拟实现
    utf8Bytes := str2bytes(utf8String)
    utf8Bytes2 := []byte(utf8String)
    for i, c := range utf8Bytes {
        fmt.Printf("utf8Bytes[%d]=%v \t (%s) \t utf8Bytes2[%d]=%v\n", i, c, string(c), i, utf8Bytes2[i])
    }

    // string([]byte) 模拟实现
    var testBytesConst = [...]byte{
        'h', 'e', 'l', 'l', 'o', ',', ' ', 0xe4, 0xb8, 0x96, 0xe7, 0x95, 0x8c, 33,
    }
    var testBytes = make([]byte, len(testBytesConst))
    for i := range testBytesConst {
        testBytes[i] = testBytesConst[i]
    }
    byte2string := bytes2str(testBytes)
    fmt.Println("btye2string = ", byte2string)

    // []rune(string) 模拟实现
    var str2rune []rune = str2runes(utf8String)
    for i, rune := range str2rune {
        fmt.Printf("str2rune[%d]=%-10v (%s)\n", i, rune, string(rune))
    }

    // string([]rune) 模拟实现
    var runesConst = [...]rune{
        'h', 'e', 'l', 'l', 'o', ',', ' ', 19990, 30028, 33,
    }
    var runes = make([]rune, len(runesConst))
    for i, rune := range runesConst {
        runes[i] = rune
    }
    var rune2string = runes2string(runes)
    fmt.Printf("string2rune=%s\n", rune2string)
}

func forOnString(s string, forBody func(i int, r rune)) {
    for i := 0; len(s) > 0; {
        r, size := utf8.DecodeRuneInString(s)
        forBody(i, r)
        s = s[size:]
        i += size
    }
}

func str2bytes(s string) []byte {
    p := make([]byte, len(s))
    for i := 0; i < len(s); i++ {
        c := s[i]
        p[i] = c
    }
    return p
}

func bytes2str(s []byte) (p string) {
    data := make([]byte, len(s))
    copy(data, s)
    // for i, c := range s {
    //     data[i] = c
    // }

    hdr := (*reflect.StringHeader)(unsafe.Pointer(&p))
    hdr.Data = uintptr(unsafe.Pointer(&data[0]))
    hdr.Len = len(s)

    return p
}

func str2runes(s string) []rune {
    var p []int32
    for len(s) > 0 {
        r, size := utf8.DecodeRuneInString(s)
        p = append(p, int32(r))
        s = s[size:]
    }
    return []rune(p)
}

func runes2string(s []int32) string {
    var p []byte
    buf := make([]byte, 3)
    for _, r := range s {
        n := utf8.EncodeRune(buf, r)
        p = append(p, buf[:n]...)
    }
    return string(p)
}

func BaseType_Slice() {
    fmt.Println("------------------------ BaseType_Slice ------------------------")

    var makeSlice = make([]int, 3, 5)
    printSlice("makeSlice --> ", makeSlice)

    var nilSlice []int
    printSlice("nilSlice --> ", nilSlice)
    /* 创建切片 */
    numbers := []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
    printSlice("numbers --> ", numbers)

    /* 打印原始切片 */
    fmt.Println("numbers ==", numbers)

    /* 打印子切片从索引1(包含) 到索引4(不包含)*/
    fmt.Println("numbers[1:4] ==", numbers[1:4])

    /* 默认下限为 0*/
    fmt.Println("numbers[:3] ==", numbers[:3])

    /* 默认上限为 len(s)*/
    fmt.Println("numbers[4:] ==", numbers[4:])

    numbers1 := make([]int, 0, 5)
    printSlice("numbers1 --> ", numbers1)

    /* 打印子切片从索引 0(包含) 到索引 2(不包含) */
    number2 := numbers[:2]
    printSlice("number2 --> ", number2)

    /* 打印子切片从索引 2(包含) 到索引 5(不包含) */
    number3 := numbers[2:5]
    printSlice("number3 --> ", number3)

    // slice 遍历方法
    fmt.Println()
    for i := range numbers {
        fmt.Printf("range i --> numbers[%d]=%d\n", i, numbers[i])
    }
    fmt.Println()
    for i, v := range numbers {
        fmt.Printf("range i,v --> numbers[%d]=%d\n", i, v)
    }
    fmt.Println()
    for i := 0; i < len(numbers); i++ {
        fmt.Printf("len --> numbers[%d]=%d\n", i, numbers[i])
    }

    // 切片尾部追加元素（内存不足的情况下导致重新分配内存）
    fmt.Println()
    var a []int
    a = append(a, 1)
    printSlice("a --> ", a)
    a = append(a, 2, 3, 4)
    printSlice("a --> ", a)
    a = append(a, []int{5, 6, 7}...) // 追加切片需要解包
    printSlice("a --> ", a)

    // 切片头部追加元素（一般会导致内存重新分配，且导致已有元素全部复制一次，比从尾部追加性能差）
    fmt.Println()
    var b = []int{1, 2, 3}
    b = append([]int{0}, b...)
    printSlice("b --> ", b)
    b = append([]int{-3, -2, -1}, b...)
    printSlice("b --> ", b)

    // 任意位置插入新切片(append 函数返回新的切片，支持链式操作)
    fmt.Println()
    var c = []int{1, 2, 4, 7}
    printSlice("c --> ", c)
    c = append(c[:2], append([]int{3}, c[2:]...)...)
    printSlice("c --> ", c)
    c = append(c[:4], append([]int{5, 6}, c[4:]...)...)
    printSlice("c --> ", c)

    // copy 助力 append 避免创建中间临时切片
    fmt.Println()
    var d = []int{1, 5, 6}
    var dd = []int{2, 3, 4}
    d = append(d, dd...)
    printSlice("d --> ", d)

    var i int = 1
    copy(d[i+len(dd):], d[i:]) // 没有专门的扩容函数
    printSlice("d --> ", d)
    copy(d[i:], dd)
    printSlice("d --> ", d)

    // 删除切片元素：头部删除、中间删除、尾部删除（最快）
    fmt.Println()
    var e = []int{1, 2, 3, 4, 5, 6}
    printSlice("e --> ", e)
    e = append(e[:0], e[1:]...) // 删除开头 1 个元素
    printSlice("e --> ", e)
    e = e[:copy(e, e[1:])] // 删除开头 1 个元素
    printSlice("e --> ", e)
    e = e[:copy(e, e[3:])] // 删除开头 3 个元素
    printSlice("e --> ", e)

    fmt.Println()
    i = 2
    var f = []int{1, 2, 3, 4, 5}
    printSlice("f --> ", f)
    f = append(f[:i], f[i+1:]...) // 删除中间 1 个元素
    printSlice("f --> ", f)
    i = 1
    var n int = 2
    f = append(f[:i], f[i+n:]...) // 删除中间 N 个元素
    printSlice("f --> ", f)

    fmt.Println()
    var g = []int{1, 2, 3, 4, 5}
    printSlice("g --> ", g)
    i = 2
    g = g[:i+copy(g[i:], g[i+1:])] // 删除中间 1 个元素
    printSlice("g --> ", g)
    i = 1
    n = 2
    g = g[:i+copy(g[i:], g[i+n:])] // 删除中间 N 个元素
    printSlice("g --> ", g)

    fmt.Println()
    var h = []int{1, 2, 3, 4, 5, 6}
    h = h[:len(h)-1]
    printSlice("h --> ", h)
    n = 3
    h = h[:len(h)-n]
    printSlice("h --> ", h)

    // 去除空格
    fmt.Println()
    var bytes = []byte{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'}
    fmt.Printf("bytes len(%d) cap(%d) --> %v\n", len(bytes), cap(bytes), bytes)
    var trimBytes = TrimSpace(bytes)
    fmt.Printf("bytes : %p     bytes[0] : 0x%08x\n", &bytes, &bytes[0])
    fmt.Printf("bytes len(%d) cap(%d) --> %v\n", len(bytes), cap(bytes), bytes)

    fmt.Println()
    fmt.Println("trimBytes --> ", trimBytes)

    bytes = []byte{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'}
    var filteredBytes = FilterByte(bytes, func(x byte) bool {
        if x == ' ' {
            return true
        } else {
            return false
        }
    })
    fmt.Println()
    fmt.Println("filteredBytes --> ", filteredBytes)

    fmt.Println()
}

// 注意：根据结果 s 被改变，b 和 s 可能共用一块底层内存
func TrimSpace(s []byte) []byte {
    b := s[:0] // 改变原数组
    // b := []byte{} // 构建新切片，保留原切片不变
    delCount := 0
    for _, x := range s {
        if x != ' ' {
            b = append(b, x)
        } else {
            delCount++
        }
    }
    if len(b) > 0 && len(s) > 0 && &b[0] == &s[0] {
        s = s[:len(s)-delCount]
    }
    fmt.Printf("s : %p    s[0] : 0x%08x\nb : %p    b[0] : 0x%08x\n", &s, &s[0], &b, &b[0])
    return b
}

func FilterByte(s []byte, fn func(x byte) bool) []byte {
    b := s[:0]
    for _, x := range s {
        if !fn(x) {
            b = append(b, x)
        }
    }
    return b
}

func printSlice(prefix string, x []int) {
    fmt.Printf("%s len=%d cap=%d slice=%v\n", prefix, len(x), cap(x), x)
}

func BaseType_Map() {
    fmt.Println("------------------------ BaseType_Map ------------------------")

    var aMap = map[int]int{}
    aMap[0] = 10
    aMap[1] = 20
    aMap[5] = 50
    fmt.Println(aMap)

    fmt.Println()
    for key, value := range aMap {
        fmt.Printf("Key:%v  Value:%v\n", key, value)
    }

    fmt.Println()
    for key := range aMap {
        fmt.Printf("Key:%v  Value:%v\n", key, aMap[key])
    }

    fmt.Println()
    for _, value := range aMap {
        fmt.Printf("Only Value:%v\n", value)
    }

    fmt.Println()
    var bMap = map[string]string{"a": "aaa", "c": "ccc", "d": "ddd"}
    fmt.Println(bMap)
    delete(bMap, "c")
    fmt.Println(bMap)
    var key string = "e"
    value, ok := bMap[key]
    if ok {
        fmt.Printf("bMap[%s]'s value is %s", key, value)
    } else {
        fmt.Printf("bMap[%s]'s value is not exist", key)
    }

    fmt.Println()
}

func BaseType_Rename() {
    fmt.Println("------------------------ BaseType_Rename ------------------------")

    type TestType []int
    var i TestType
    var t []int

    printSlice("t --> ", t)

    // i = append(i, 1, 2, 3)
    // t = append(t, 1, 2, 3)
    t = i

    printSlice("i --> ", i)
    printSlice("t --> ", t)

    type IntType int
    var a IntType
    var b int
    // a = b // https://www.coder.work/article/212328 https://golang.org/ref/spec#Assignability
    fmt.Printf("a=%v  b=%v\n", a, b)
}

type Point struct{ X, Y float64 }

func (p *Point) toString() string {
    var retValue string = fmt.Sprintf("Point (%.3f, %.3f)", p.X, p.Y)
    return retValue
}

type ColoredPoint struct {
    Point
    Color color.RGBA
}

func (cp *ColoredPoint) toString() string {
    var retValue string = fmt.Sprintf("Point (%.3f, %.3f)  Color : [%d, %d, %d, %d]",
        cp.Point.X, cp.Point.Y,
        cp.Color.R, cp.Color.G, cp.Color.B, cp.Color.A)
    return retValue
}

func BaseType_Inherit() {
    fmt.Println("------------------------ BaseType_Inherit ------------------------")

    fmt.Println()
    var p1 = &Point{
        X: 100,
        Y: 20.1235,
    }
    fmt.Println(p1.toString())
    var p2 = ColoredPoint{
        Color: color.RGBA{
            R: 10,
            G: 20,
            B: 30,
            A: 40,
        },
    }
    p2.X = 12.34
    p2.Y = 56.7890
    fmt.Println(p2.Point.toString())
    fmt.Println(p2.toString())

    fmt.Println()
}

func BaseType_Interface() {
    fmt.Println("------------------------ BaseType_Interface ------------------------")

    fmt.Println()
    var a = []interface{}{123, "abc", false}
    fmt.Println(a...)
    fmt.Println(a)

    fmt.Println()
    for i, value := range a {
        fmt.Printf("a[%d] --> %v\n", i, value)
    }

    fmt.Println()
    printInterfaceFunc(a)
    fmt.Println()
    printInterfaceFunc(a...)

    fmt.Println()
    deferTest()

    fmt.Println()
}

func printInterfaceFunc(a ...interface{}) {
    fmt.Println("Enter printInterfaceFunc ...")
    defer func() {
        fmt.Println("Leave printInterfaceFunc ...")
    }()
    fmt.Println("Before printInterfaceFunc ...")
    fmt.Println(a...)
    fmt.Println("After printInterfaceFunc ...")
}

// defer 与 函数闭包
// 1. 函数退出时（前）调用 defer 修饰的函数
// 2. 按 defer 函数声明顺序逆序调用
// 3. defer 会立即对调用参数求值
// 4. 循环语句中慎用 defer
func deferTest() {
    for i := 0; i < 3; i++ {
        i := i // 没有该语句：输出 3 次 i --> 3
        defer func() {
            fmt.Println("i-1 --> ", i)
        }()
    }

    defer func() { fmt.Println() }()

    // for i := 0; i < 3; i++ {
    //     defer func() {
    //         fmt.Println("i-2 --> ", i) // 输出 3 次 i --> 3    会有 go vet 警告
    //     }()
    // }

    defer func() { fmt.Println() }()

    for i := 0; i < 3; i++ {
        defer func(i int) {
            fmt.Println("i-3 --> ", i)
        }(i)
    }
}
