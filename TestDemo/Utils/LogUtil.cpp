#include "LogUtil.h"

namespace Shuanglong::Utils
{
#define LOG_COLOR_RESET   "\033[0m"
#define LOG_COLOR_DEBUG   "\033[1m\033[37m"
#define LOG_COLOR_INFO    "\033[1m\033[36m"
#define LOG_COLOR_WARN    "\033[1m\033[33m"
#define LOG_COLOR_ERROR   "\033[1m\033[31m"
#define LOG_COLOR_FATAL   "\033[35m"

    LogUtil::~LogUtil()
    {
    }

    void LogUtil::Debug(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_DEBUG << LogUtil::GetAssembledMessage(msgBuffer, LOG_LEVEL_DEBUG) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }
    
    void LogUtil::Debug(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_DEBUG << LogUtil::GetAssembledMessage(msgBuffer, codeLocation, LOG_LEVEL_DEBUG) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }
    
    void LogUtil::Info(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_INFO << LogUtil::GetAssembledMessage(msgBuffer, LOG_LEVEL_INFO) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }

    void LogUtil::Info(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_INFO << LogUtil::GetAssembledMessage(msgBuffer, codeLocation, LOG_LEVEL_INFO) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }
    
    void LogUtil::Warn(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_WARN << LogUtil::GetAssembledMessage(msgBuffer, LOG_LEVEL_WARN) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }

    void LogUtil::Warn(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_WARN << LogUtil::GetAssembledMessage(msgBuffer, codeLocation, LOG_LEVEL_WARN) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }
    
    void LogUtil::Error(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_ERROR << LogUtil::GetAssembledMessage(msgBuffer, LOG_LEVEL_ERROR) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }

    void LogUtil::Error(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_ERROR << LogUtil::GetAssembledMessage(msgBuffer, codeLocation, LOG_LEVEL_ERROR) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }
    
    void LogUtil::Fatal(const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_FATAL << LogUtil::GetAssembledMessage(msgBuffer, LOG_LEVEL_FATAL) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }

    void LogUtil::Fatal(const CodeLocation &codeLocation, const char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << LOG_COLOR_FATAL << LogUtil::GetAssembledMessage(msgBuffer, codeLocation, LOG_LEVEL_FATAL) << std::endl;
        std::cout << LOG_COLOR_RESET;
    }

    std::string LogUtil::GetAssembledMessage(const char *pMsgBuffer, LogLevelType logLevel)
    {
        std::string retValue = LogUtil::GetSystemTimeString();
        retValue.append(" [").append(GetLevelString(logLevel)).append("] ");
        retValue.append(pMsgBuffer);
        return retValue;
    }

    std::string LogUtil::GetAssembledMessage(const char *pMsgBuffer, const CodeLocation &codeLocation, LogLevelType logLevel)
    {
        std::string retValue = LogUtil::GetSystemTimeString();
        retValue.append(" [").append(GetLevelString(logLevel)).append("] ");
        retValue.append(pMsgBuffer);
        retValue.append(" <=== ").append(codeLocation.ToString());
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
            case LOG_LEVEL_FATAL:
                retValue = "FATAL";
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

        retValue += "[" + mFunctionName + "]";
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

