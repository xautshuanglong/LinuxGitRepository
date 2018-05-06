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
        LogUtil::Debug(CODE_LOCATION, "%d %s LogUtil testing");
        std::cout << "argc=" << argc << std::endl;
        
        for (int i=0; i<argc; ++i)
        {
            std::cout << *argv++ << std::endl;
        }
        return 0;
    }
}

