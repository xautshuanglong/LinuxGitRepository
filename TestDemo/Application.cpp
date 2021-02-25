#include "Application.h"

#include "Common.h"

#include <sstream>

using namespace Shuanglong::Utils;

namespace Shuanglong
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    int Application::Run(int argc, char *argv[])
    {
        this->PrintArguments(argc, argv);
        LogUtil::Debug(CODE_LOCATION, "Start running %d", 666);

        return 0;
    }

    void Application::PrintArguments(int argc, char *argv[])
    {
        std::ostringstream sstring;
        for (int i=0; i<argc; ++i)
        {
            if (i != 0)
            {
                sstring << " ";
            }
            sstring << *argv++;
        }
        LogUtil::Debug(CODE_LOCATION, "Command Line: %s", sstring.str().c_str());
    }
}

