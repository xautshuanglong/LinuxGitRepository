#include "LogUtil.h"

namespace Shuanglong::Utils
{
//    LogUtil::LogUtil()
//    {
//    }
//
    LogUtil::~LogUtil()
    {
    }

    void LogUtil::Debug(char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << msgBuffer << std::endl;
    }
    
    void LogUtil::Debug(CodeLocation codeLocation, char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << codeLocation.ToString() << " --> " << msgBuffer << std::endl;
    }
    
    void LogUtil::Info(char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << msgBuffer << std::endl;
    }

    void LogUtil::Info(CodeLocation codeLocation, char *format, ...)
    {
        char msgBuffer[DEFAULT_LOG_BUFFER_LENGTH] = { 0 };
        DEFAULT_LOG_FORMAT(msgBuffer, format, DEFAULT_LOG_BUFFER_LENGTH);
        std::cout << codeLocation.ToString() << " --> " << msgBuffer << std::endl;
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

