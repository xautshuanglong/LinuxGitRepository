#include "Application.h"

#include <iostream>

#include "utils/LogUtil.h"

using namespace Shuanglong::Utils;

namespace Shuanglong
{
    Application::Application()
    {
        std::cout << "Application::Application()" << std::endl;
    }

    Application::~Application()
    {
        std::cout << "Application::~Application()" << std::endl;
    }

    int Application::Run(int argc, char* argv[])
    {
        for (int i=0; i<argc; ++i)
        {
            std::cout << "argv[" << i << "] --> " << *argv++ << std::endl;
        }

        LogUtil::Debug(CODE_LOCATION, "Start running %d", 666);

        return 0;
    }
}

