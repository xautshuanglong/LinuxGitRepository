#include <iostream>

#include "Application.h"
#include "CommandLine.h"
#include "utils/StringUtil.h"

using namespace Shuanglong;
using namespace Shuanglong::Utils;

int main(int argc, char **argv)
{
#ifdef DEBUG
    std::cout << "--------------------- ShuanglongServer ( DEBUG ) -------------------------" << std::endl;
#else
    std::cout << "--------------------- ShuanglongServer ( NDEBUG ) -------------------------" << std::endl;
#endif

    CommandLine cmdLine;
    cmdLine.ParseCommandArguments(argc, argv);

    StringUtil strutil;
    Application app;
    app.Run(argc, argv);
    
#ifdef NDEBUG
    std::cout << "---------------------------- END ( NDEBUG ) -------------------------------" << std::endl;
#else
    std::cout << "---------------------------- END ( DEBUG ) -------------------------------" << std::endl;
#endif
    
    return 0;
}

