/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-20 15:32:15
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-29 17:18:39
 *  FilePath: \GoLearning\os_api\thread_linux.go
 *  Description:
\********************************************************************/

package os_api

import (
    "golang.org/x/sys/unix"
)

func GetCurrentThreadID() (tid uint32) {
    tid = uint32(unix.Gettid())
    return
}
