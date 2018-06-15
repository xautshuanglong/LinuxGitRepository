#include "Application.h"

#include "Common.h"
#include "Utils/LogUtil.h"

using namespace Shuanglong::Utils;

namespace Shuanglong
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    int Application::Run(int argc, char* argv[])
    {
        for (int i=0; i<argc; ++i)
        {
            std::cout << *argv++ << " ";
        }
        std::cout << std::endl;

        LogUtil::Debug(CODE_LOCATION, "Start running %d", 666);

        return 0;
    }
}

