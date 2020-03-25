#include "LogUtil.h"

#include <stdarg.h>
#include <sys/time.h>

#include <iostream>
#include <sstream>

namespace Shuanglong::Utils
{
    LogUtil::~LogUtil()
    {
    }

    void LogUtil::Debug(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << msgBuffer << std::endl;
    }
    
    void LogUtil::Debug(CodeLocation codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);

        std::string tempMsg = GetSystemTimeString();
        tempMsg.append(" [").append(GetLevelString(LOG_LEVEL_DEBUG)).append("] ");
        tempMsg.append(msgBuffer);
        tempMsg.append(" <== ").append(codeLocation.ToString());

        std::cout << tempMsg << std::endl;
    }
    
    void LogUtil::Info(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << msgBuffer << std::endl;
    }

    void LogUtil::Info(CodeLocation codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << codeLocation.ToString() << " --> " << msgBuffer << std::endl;
    }

    std::string LogUtil::GetSystemTimeString()
    {
        char timeBuffer[50] = {0};
        struct timeval tv;
        gettimeofday(&tv, NULL);
        struct tm *pLocalTime = localtime(&tv.tv_sec);
        int milliSeconds = (int)tv.tv_usec / 1000;
        snprintf(timeBuffer, sizeof(timeBuffer)-1, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                pLocalTime->tm_year + 1990,
                pLocalTime->tm_mon + 1,
                pLocalTime->tm_mday,
                pLocalTime->tm_hour,
                pLocalTime->tm_min,
                pLocalTime->tm_sec,
                milliSeconds);
        return std::string(timeBuffer);
    }

    std::string LogUtil::GetLevelString(LogLevelType logLevel)
    {
        std::string retValue = "UNKNOW";
        switch (logLevel)
        {
            case LOG_LEVEL_NONE:
                retValue = "NONE";
                break;
            case LOG_LEVEL_DEBUG:
                retValue = "DEBUG";
                break;
            case LOG_LEVEL_INFO:
                retValue = "INFO";
                break;
            case LOG_LEVEL_WARN:
                retValue = "WARN";
                break;
            case LOG_LEVEL_ERROR:
                retValue = "ERROR";
                break;
            default:
                break;
        }
        
        return retValue;
    }

    CodeLocation::CodeLocation()
    {
    }

    CodeLocation::CodeLocation(CodeLocation& originalObj)
    {
    }

    CodeLocation::CodeLocation(const CodeLocation& originalObj)
    {
    }

    CodeLocation::CodeLocation(std::string function, std::string filename, int lineNumber)
    {
        mFunctionName = function;
        mSourceFileName = filename;
        mLineNumber = lineNumber;
    }

    std::string CodeLocation::ToString()
    {
        std::string retValue;

        retValue += "[ " + mFunctionName + " ]";
        retValue += " " + mSourceFileName + ":" + NumberToString(mLineNumber);

        return retValue;
    }
    
    template<class T> std::string CodeLocation::NumberToString(T number)
    {
        std::stringstream ss;
        ss << number;
        return ss.str();
    }
}

