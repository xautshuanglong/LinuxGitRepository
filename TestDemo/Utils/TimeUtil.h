#ifndef _TIME_UTIL_H_
#define _TIME_UTIL_H_

#include <string>

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

#endif // _TIME_UTIL_H_

