#ifndef LOGUTIL_H
#define LOGUTIL_H

#include "../Common.h"

namespace Shuanglong::Utils
{
#define CODE_LOCATION        Shuanglong::Utils::CodeLocation(__PRETTY_FUNCTION__, __FILE__, __LINE__)
#define CODE_LOCATION_STRING Shuanglong::Utils::CodeLocation(__PRETTY_FUNCTION__, __FILE__, __LINE__).ToString()

#define DEFAULT_LOG_BUFFER_LENGTH 1024

#define DEFAULT_LOG_FORMAT(buffer, fmt, length) \
    va_list vaList;\
    va_start(vaList, fmt);\
    vsnprintf(buffer, DEFAULT_LOG_BUFFER_LENGTH - 1, fmt, vaList);\
    va_end(vaList);

    class CodeLocation
    {
        private:
            std::string      mFunctionName;
            std::string      mSourceFileName;
            int              mLineNumber;

        public:
            CodeLocation();
            CodeLocation(CodeLocation& originalObj);
            CodeLocation(const CodeLocation& originalObj);
            CodeLocation(std::string function, std::string filename, int lineNumber);

            std::string ToString();

        private:
            template<class T> std::string NumberToString(T number);
    };

    class LogUtil
    {
        private:
            int mValue;

        public:
            LogUtil() = delete;
            ~LogUtil();

            static void Debug(char *format, ...);
            static void Debug(CodeLocation codeLocation, char *format, ...);

            static void Info(char *format, ...);
            static void Info(CodeLocation codeLocation, char *format, ...);
    };
}

#endif

