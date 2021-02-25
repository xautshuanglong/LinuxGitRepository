#include "MainLoop.h"

#include <cstddef>
#include <cstdlib>
#include <unistd.h>

#include "../Utils/LogUtil.h"

using namespace Shuanglong::Utils;

namespace Shuanglong::EventLoop
{
    MainLoop::MainLoop() :
        mRunningFlag(true),
        mValue(0)
    {
    }

    MainLoop::~MainLoop()
    {
    }

    void MainLoop::Start()
    {
        if (!mRunningFlag)
        {
            mRunningFlag = true;
        }
    }

    void MainLoop::Stop()
    {
        mRunningFlag = false;
    }

    void* MainLoop::ThreadRoutine(void *pArgument)
    {
        if (pArgument == NULL) return NULL;
        MainLoop *pMainLoop = static_cast<MainLoop*>(pArgument);
        if (pMainLoop == NULL) return NULL;

        while (pMainLoop->mRunningFlag)
        {
            LogUtil::Info(CODE_LOCATION, "Inside LibeventLoopThreadFunc tid : %lu", pthread_self());
            sleep(1);
        }
        pMainLoop->mRunningFlag = false;

        return NULL;
    }

    void MainLoop::SetValue(int value)
    {
        mValue = value;
    }
}

