#include <iostream>

#include "utils/LogUtil.h"
#include "utils/StringUtil.h"

using namespace Shuanglong::Utils;

int main(int argc, char **argv)
{
    std::cout << "--------------------- ShuanglongServer -------------------------" << std::endl;

    LogUtil log;
    StringUtil strutil;
    
    std::cout << "---------------------------- END -------------------------------" << std::endl;

    // warning: nested namespace definition is a C++1z extension; define each namespace separately [-Wc++1z-extensions]

    return 0;
}
