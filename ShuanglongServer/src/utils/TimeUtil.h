#ifndef TIME_UTIL_H
#define TIME_UTIL_H

#include "../Common.h"

namespace Shuanglong::Utils
{
    enum class TimestampStandard
    {
        LOCAL,
        GREENWICH
    };

    class TimeUtil final
    {
        private:
            int mValue;
        public:
            TimeUtil() = delete;
            ~TimeUtil() = delete;

            static long long CurrentSecondsFromEpoch();
            static long long CurrentMilliSecondsFromEpoch();
            static std::string CurrentTimestampString(TimestampStandard timeStandardi = TimestampStandard::LOCAL);

        private:
            static std::string FormatTimestamp(struct tm *pTimestamp, struct timeval *pTimeVal);
    };
}

#endif

