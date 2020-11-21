/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-21 22:44:11
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-21 23:01:44
 *  FilePath: /GoLearning/demo/a/a.go
 *  Description:
\********************************************************************/

package a

import "fmt"
import "./b"
import "./e"

// import "./b/internal"

func AFunction() {
	fmt.Println("Inside AFunction ...")

	b.BFunction()
	e.EFunction()
	// internal.InternalFunction()
}
