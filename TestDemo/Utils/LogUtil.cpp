#include "LogUtil.h"

namespace Shuanglong::Utils
{
    LogUtil::LogUtil()
    {
        std::cout << "LogUtil::LogUtil()" << std::endl;
    }

    LogUtil::~LogUtil()
    {
        std::cout << "LogUtil::~LogUtil()" << std::endl;
    }

    void LogUtil::Debug(std::string& message)
    {
    }
    
    void LogUtil::Debug(CodeLocation codeLocation, std::string message)
    {
        std::cout << __FUNCTION__ << std::endl;
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        std::cout << message << " " << codeLocation.ToString() << std::endl;
    }

    void LogUtil::Debug(CodeLocation& codeLocation, std::string& message)
    {
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

