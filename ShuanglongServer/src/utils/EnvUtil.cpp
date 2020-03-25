#include "EnvUtil.h"

namespace Shuanglong::Utils
{
    EnvUtil::EnvUtil()
    {
    }


    EnvUtil::~EnvUtil()
    {
    }

    bool EnvUtil::IsEndianBig()
    {
        bool retValue = false;
        union EndianTest
        {
            int intValue;
            char bytes[4];
        };
        EndianTest endian = { 0 };
        endian.intValue = 0x12345678;
        if (endian.bytes[0] == 0x12)
        {
            retValue = true;
        }

        return retValue;
    }

    bool EnvUtil::IsEndianLittle()
    {
        bool retValue = false;
        int endianTest = 0x12345678;
        char *pByte = (char*)&endianTest;
        if (*pByte == 0x78)
        {
            retValue = true;
        }

        return retValue;
    }
}

