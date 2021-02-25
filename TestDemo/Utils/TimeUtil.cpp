#include "TimeUtil.h"

#include <iostream>
#include <sstream>
#include <sys/time.h>

namespace Shuanglong::Utils
{
    long long TimeUtil::CurrentSecondsFromEpoch()
    {
        time_t retTime = 0;
        
        struct timeval timeOfDay;
        int res = gettimeofday(&timeOfDay, NULL);
        if (res == 0)
        {
            std::cout << "gettimeofday successfully!" << std::endl;
            retTime = timeOfDay.tv_sec;
        }
        else
        {
            retTime = time(NULL);
        }

        return retTime;
    }

    long long TimeUtil::CurrentMilliSecondsFromEpoch()
    {
        int retValue = 0;
        return retValue;
    }

    std::string TimeUtil::CurrentTimestampString(TimestampStandard timeStandard /* = TimestampStandard::LOCAL*/)
    {
        std::string retValue;
        struct tm *pOutTimestamp = NULL;
        struct timeval timeOfDay;
        gettimeofday(&timeOfDay, NULL);

        switch (timeStandard)
        {
            case TimestampStandard::LOCAL:
                pOutTimestamp = localtime(&timeOfDay.tv_sec);
                break;
            case TimestampStandard::GREENWICH:
                pOutTimestamp = gmtime(&timeOfDay.tv_sec);
                break;
            default:
                break;
        }

        if (pOutTimestamp != NULL)
        {
            retValue = FormatTimestamp(pOutTimestamp, &timeOfDay);
        }

        return retValue;
    }

    std::string TimeUtil::FormatTimestamp(struct tm *pTimestamp, struct timeval *pTimeVal)
    {
        std::ostringstream sstring;
        sstring << pTimestamp->tm_year + 1900;
        sstring << "-";
        int mon = pTimestamp->tm_mon + 1;
        if (mon < 10)
        {
            sstring << "0";
        }
        sstring << mon;
        sstring << "-";
        int mday = pTimestamp->tm_mday;
        if (mday < 10)
        {
            sstring << "0";
        }
        sstring << mday;
        sstring << " ";
        if (pTimestamp->tm_hour < 10)
        {
            sstring << "0";
        }
        sstring << pTimestamp->tm_hour;
        sstring << ":";
        if (pTimestamp->tm_min < 10)
        {
            sstring << "0";
        }
        sstring << pTimestamp->tm_min;
        sstring << ":";
        if (pTimestamp->tm_sec < 10)
        {
            sstring << "0";
        }
        sstring << pTimestamp->tm_sec;
        sstring << ".";
        sstring << pTimeVal->tv_usec / 1000;

        return sstring.str();
    }
}

