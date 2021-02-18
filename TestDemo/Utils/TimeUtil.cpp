#include "TimeUtil.h"

#include <time.h>

namespace Shuanglong::Utils
{
    long long TimeUtil::CurrentSecondsFromEpoch()
    {
        time_t retTime = time(NULL);
        std::cout << "retTime=" << retTime << std::endl;
        
        struct tm *pLocalTime = localtime(&retTime);

        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::ostringstream sstring;
        sstring << pLocalTime->tm_year + 1900;
        sstring << "-";
        int mon = pLocalTime->tm_mon + 1;
        if (mon < 10)
        {
            sstring << "0";
        }
        sstring << mon;
        sstring << "-";
        int mday = pLocalTime->tm_mday;
        if (mday < 10)
        {
            sstring << "0";
        }
        sstring << mday;
        sstring << " ";
        if (pLocalTime->tm_hour < 10)
        {
            sstring << "0";
        }
        sstring << pLocalTime->tm_hour;
        sstring << ":";
        if (pLocalTime->tm_min < 10)
        {
            sstring << "0";
        }
        sstring << pLocalTime->tm_min;
        sstring << ":";
        if (pLocalTime->tm_sec < 10)
        {
            sstring << "0";
        }
        sstring << pLocalTime->tm_sec;
        std::cout << "CurrentTime: " << sstring.str() << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        time_t time1 = 100;
        time_t time2 = 200;
        double timeDiff = difftime(time2, time1);
        std::cout << time2 << " - " << time1 << " = " << timeDiff << std::endl;
        
        struct timeval timeOfDay;
        int res = gettimeofday(&timeOfDay, NULL);
        if (res == 0)
        {
            std::cout << "timeOfDay: " << timeOfDay.tv_sec << std::endl;
        }
        else
        {
            std::cout << "gettimeofday failed: " << errno << std::endl;
        }

        return retTime;
    }

    long long TimeUtil::CurrentMilliSecondsFromEpoch()
    {
        int retValue = 0;
        return retValue;
    }
}

