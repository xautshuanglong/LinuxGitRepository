#include "MainLoop.h"
// 系统 API
#include <cstddef>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
// 第三方链接库
#include <event.h>
// 自定义
#include "../Utils/LogUtil.h"

using namespace Shuanglong::Utils;

namespace Shuanglong::EventLoop
{
    MainLoop::MainLoop():
        mEventThread(0)
    {
        LogUtil::Debug(CODE_LOCATION, "LibEvent Version: %s", event_get_version());
        mpEventBase = event_base_new();
        mpEventTimer = event_new(mpEventBase, -1, EV_TIMEOUT, MainLoop::EventCallback, this);
        mpTimeValue = new struct timeval();
        mpTimeValue->tv_sec = 1;
        mpTimeValue->tv_usec = 0; 
    }

    MainLoop::~MainLoop()
    {
        this->Stop();
    }

    void MainLoop::Start()
    {
        pthread_create(&mEventThread, NULL, MainLoop::ThreadStartRoutine, this);

        void *pRetValue = NULL;
        int retCode = pthread_join(mEventThread, &pRetValue);
        mEventThread = 0;
        LogUtil::Warn(CODE_LOCATION, "After pthread_join retCode=%d  pRetValue=%p", retCode, pRetValue);
    }

    void MainLoop::Stop()
    {
        LogUtil::Debug(CODE_LOCATION, "stopping main loop ...");
        if (mpEventTimer)
        {
            event_del(mpEventTimer);
            event_free(mpEventTimer);
            mpEventTimer = NULL;
        }
        if (mpEventBase && !event_base_got_break(mpEventBase))
        {
            event_base_loopbreak(mpEventBase);
        }
//        if (!event_base_got_exit(mpEventBase))
//        {
//            event_base_loopexit(mpEventBase, NULL);
//        }
        LogUtil::Debug(CODE_LOCATION, "have broke the event loop ...");
    }

    void* MainLoop::Run()
    {
        event_add(mpEventTimer, mpTimeValue);
        event_base_dispatch(mpEventBase);
        event_base_free(mpEventBase);
        mpEventBase = NULL;
        LogUtil::Warn(CODE_LOCATION, "libevent timer thread will exiting!");
        
        return NULL;
    }

    void MainLoop::TimerEventHandler()
    {
        LogUtil::Info(CODE_LOCATION, "Inside function ...");
        event_add(mpEventTimer, mpTimeValue);
    }

    void* MainLoop::ThreadStartRoutine(void *pArgument)
    {
        if (pArgument == NULL) return NULL;
        MainLoop *pMainLoop = static_cast<MainLoop*>(pArgument);
        if (pMainLoop == NULL) return NULL;
        return pMainLoop->Run();
    }

    void MainLoop::EventCallback(int fd, short event, void *pArgument)
    {
        if (pArgument == NULL) return;

        MainLoop *pMainLoop = static_cast<MainLoop*>(pArgument);
        if (pMainLoop == NULL) return;

        switch(event)
        {
            case EV_TIMEOUT:
                pMainLoop->TimerEventHandler();
                break;
            default:
                break;
        }
    }
}

