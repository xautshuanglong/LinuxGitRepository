/********************************************************************\
 *  Author: ,: xautshuanglong
 *  Date: ,: 2020-10-20 15:32:15
 *  LastEditor: ,: xautshuanglong
 *  LastEditTime: ,: 2020-10-20 15:55:52
 *  FilePath: ,: \GoLearning\os_api\process_linux.go
 *  Description: ,:
\********************************************************************/
package os_api

import (
    "golang.org/x/sys/unix"
)

func GetCurrentProcessID() (pid int) {
    return unix.Getpid()
}
