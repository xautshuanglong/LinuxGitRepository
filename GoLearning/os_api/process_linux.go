/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 15:55:08
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-29 17:19:11
 *  FilePath: \GoLearning\os_api\process_linux.go
 *  Description:
\********************************************************************/

package os_api

import (
    "golang.org/x/sys/unix"
)

func GetCurrentProcessID() (pid uint32) {
    pid = uint32(unix.Getpid())
    return
}
