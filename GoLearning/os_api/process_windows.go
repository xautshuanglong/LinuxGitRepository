/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 15:55:14
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-29 17:18:52
 *  FilePath: \GoLearning\os_api\process_windows.go
 *  Description:
\********************************************************************/

package os_api

import (
    "golang.org/x/sys/windows"
)

func GetCurrentProcessID() (pid uint32) {
    return windows.GetCurrentProcessId()
}
