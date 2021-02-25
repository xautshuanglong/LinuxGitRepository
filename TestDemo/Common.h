#ifndef _COMMON_H_
#define _COMMON_H_

//#include <stdarg.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <sys/time.h>
#include <csignal>

#include "Utils/LogUtil.h"
#include "Utils/TimeUtil.h"
#include "Utils/EnvUtil.h"
#include "Utils/StringUtil.h"
#include "EventLoop/MainLoop.h"

// 信号值定义
#define SIGNAL_CONTROL SIGUSR1  // 通过该信号发送控制指令
#define SIGNAL_TIMER   SIGUSR2  // 操作系统定时器信号使用

#endif // _COMMON_H_

