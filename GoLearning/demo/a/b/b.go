/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-21 22:37:18
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-22 18:43:46
 *  FilePath: /GoLearning/demo/a/b/b.go
 *  Description:
\********************************************************************/

package b

import "fmt"
import "./internal"
import "./internal/c"
import "./internal/c/d"
import "./internal/f"

import _ "unsafe"

func BFunction() {
	fmt.Println("Inside BFunction ...")
	internal.InternalFunction()
	c.CFunction()
	d.DFunction()
	f.FFunction()

	b_privateFunction()
}

//go:linkname b_privateFunction b.b_privateFunction
func b_privateFunction() {
	fmt.Println("Inside b_privateFunction ...")
}
