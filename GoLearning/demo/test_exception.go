/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-11-23 14:41:54
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 14:46:18
 *  FilePath: /GoLearning/demo/test_exception.go
 *  Description:
\********************************************************************/

package demo

func Exception_TestEntry() {
    Exception_MapError()
}

func Exception_MapError() {
    if v, ok := m["key"]; ok {
        return v
    }
}
