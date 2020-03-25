#ifndef ENV_UTIL_H 
#define ENV_UTIL_H 

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

#endif
