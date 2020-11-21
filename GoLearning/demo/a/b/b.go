/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-21 22:37:18
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-21 22:58:48
 *  FilePath: /GoLearning/demo/a/b/b.go
 *  Description:
\********************************************************************/

package b

import "fmt"
import "./internal"
import "./internal/c"
import "./internal/c/d"
import "./internal/f"

func BFunction() {
	fmt.Println("Inside BFunction ...")
	internal.InternalFunction()
	c.CFunction()
	d.DFunction()
	f.FFunction()
}
