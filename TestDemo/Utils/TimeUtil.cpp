#include "TimeUtil.h"

namespace Shuanglong::Utils
{
    long long TimeUtil::CurrentSecondsFromEpoch()
    {
        static int retValue = 0;
        ++retValue;
        return retValue;
    }

    long long TimeUtil::CurrentMilliSecondsFromEpoch()
    {
        int retValue = 0;
        return retValue;
    }
}

