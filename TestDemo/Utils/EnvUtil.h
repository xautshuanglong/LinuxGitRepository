#ifndef _ENV_UTIL_H_
#define _ENV_UTIL_H_

namespace Shuanglong::Utils
{
    class EnvUtil
    {
        private:
            EnvUtil();

        public:
            ~EnvUtil();

            static bool IsEndianBig();
            static bool IsEndianLittle();
    };
}

#endif // _ENV_UTIL_H_
