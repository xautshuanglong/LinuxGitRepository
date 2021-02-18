#ifndef TIME_UTIL_H
#define TIME_UTIL_H

namespace Shuanglong::Utils
{
    class TimeUtil final
    {
        private:
            int mValue;
        public:
            TimeUtil() = delete;
            ~TimeUtil() = delete;

            static long long CurrentSecondsFromEpoch();
            static long long CurrentMilliSecondsFromEpoch();
    };
}

#endif

