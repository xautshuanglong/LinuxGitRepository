#include "LogUtil.h"

#include <iostream>

namespace Shuanglong::Utils
{
    LogUtil::LogUtil()
    {
        std::cout << "LogUtil::LogUtils()" << std::endl;
    }

    LogUtil::~LogUtil()
    {
        std::cout << "LogUtil::~LogUtils()" << std::endl;
    }
}
