#include "TimeUtil.h"

#include <time.h>

namespace Shuanglong::Utils
{
    long long TimeUtil::CurrentSecondsFromEpoch()
    {
        time_t retTime = time(NULL);
        std::cout << "retTime=" << retTime << std::endl;
        
        struct tm *pLocalTime = localtime(&retTime);

        std::cout << "---------------------" << std::endl;
        std::cout << "year=" << pLocalTime->tm_year + 1900 << std::endl;
        std::cout << "month=" << pLocalTime->tm_mon + 1 << std::endl;
        std::cout << "day=" << pLocalTime->tm_mday << std::endl;
        std::cout << "---------------------" << std::endl;

        return retTime;
    }

    long long TimeUtil::CurrentMilliSecondsFromEpoch()
    {
        int retValue = 0;
        return retValue;
    }
}

