#include "LogUtil.h"

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
    
    void LogUtil::Debug(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LogUtil::GetAssembledMessage(msgBuffer, codeLocation) << std::endl;
    }
    
    void LogUtil::Info(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << msgBuffer << std::endl;
    }

    void LogUtil::Info(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LogUtil::GetAssembledMessage(msgBuffer, codeLocation) << std::endl;
    }

    std::string LogUtil::GetAssembledMessage(const char *pMsgBuffer, const CodeLocation &codeLocation)
    {
        std::string retValue = LogUtil::GetSystemTimeString();
        retValue.append(" [").append(GetLevelString(LOG_LEVEL_DEBUG)).append("] ");
        retValue.append(pMsgBuffer);
        retValue.append(" <--- ").append(codeLocation.ToString());

        return retValue;
    }

    std::string LogUtil::GetSystemTimeString()
    {
        char timeBuffer[50] = {0};
        struct timeval tv;
        gettimeofday(&tv, NULL);
        struct tm *pLocalTime = localtime(&tv.tv_sec);
        int milliSeconds = (int)tv.tv_usec / 1000;
        snprintf(timeBuffer, sizeof(timeBuffer)-1, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                pLocalTime->tm_year + 1900,
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

    CodeLocation::CodeLocation(const CodeLocation& originalObj)
    {
        if (&originalObj == this) return;
        //=========================================
        mFunctionName = originalObj.mFunctionName;
        mSourceFileName = originalObj.mSourceFileName;
        mLineNumber = originalObj.mLineNumber;
    }

    CodeLocation::CodeLocation(std::string function, std::string filename, int lineNumber)
    {
        mFunctionName = function;
        mSourceFileName = filename;
        mLineNumber = lineNumber;
    }

    std::string CodeLocation::ToString() const
    {
        std::string retValue;

        retValue += "[ " + mFunctionName + " ]";
        retValue += " " + mSourceFileName + ":" + this->NumberToString(mLineNumber);

        return retValue;
    }
    
    template<class T> std::string CodeLocation::NumberToString(T number) const
    {
        std::stringstream ss;
        ss << number;
        return ss.str();
    }
}

