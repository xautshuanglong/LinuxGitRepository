/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-21 22:44:11
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-22 18:42:34
 *  FilePath: /GoLearning/demo/a/a.go
 *  Description:
\********************************************************************/

package a

import "fmt"
import "./b"
import "./e"

import _ "unsafe"

//go:linkname b_privateFunction b.b_privateFunction
func b_privateFunction()

func AFunction() {
	fmt.Println("Inside AFunction ...")

	b.BFunction()
	e.EFunction()

	b_privateFunction()
}
