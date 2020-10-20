/********************************************************************\
 *  Author: ,: xautshuanglong
 *  Date: ,: 2020-10-20 15:32:27
 *  LastEditor: ,: xautshuanglong
 *  LastEditTime: ,: 2020-10-20 15:57:26
 *  FilePath: ,: \GoLearning\os_api\trhead_windows.go
 *  Description: ,:
\********************************************************************/
package os_api

import (
    "golang.org/x/sys/windows"
)

func GetCurrentThreadID() (tid uint32) {
    return windows.GetCurrentThreadId()
}
