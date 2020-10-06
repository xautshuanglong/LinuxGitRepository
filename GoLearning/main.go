//
// Author: xautshuanglong
// Date: 2020-10-06 14:51:34
// LastEditor: xautshuanglong
// LastEditTime: 2020-10-06 15:30:40
// FilePath: /GoLearning/main.go
// Description:
//
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	for index, arg := range os.Args {
		fmt.Println("Args["+strconv.Itoa(index)+"] = ", arg)
	}

	var argCount int = len(os.Args)
	if argCount > 2 {
		fmt.Println("Hello")
	} else {
		fmt.Println("World")
	}

	fmt.Printf("Hello, world!\n")
}
