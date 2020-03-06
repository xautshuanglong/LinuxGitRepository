#include <iostream>

#include "Application.h"
#include "utils/LogUtil.h"
#include "utils/StringUtil.h"

using namespace Shuanglong;
using namespace Shuanglong::Utils;

int main(int argc, char **argv)
{
    std::cout << "--------------------- ShuanglongServer -------------------------" << std::endl;

    LogUtil log;
    StringUtil strutil;
    Application app;
    
    std::cout << "---------------------------- END -------------------------------" << std::endl;
    
    // warning: nested namespace definition is a C++1z extension; define each namespace separately [-Wc++1z-extensions]

#if DEBUG
    std::cout << "define DEBUG when excute configure" << std::endl;
#else
    std::cout << "do not define DEBUG" << std::endl;
#endif

    return 0;
}

