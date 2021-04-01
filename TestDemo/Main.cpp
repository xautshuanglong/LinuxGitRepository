#include "Common.h"
#include "Application.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>

#include <pthread.h>
#include <thread>

#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)

#include <event2/event-config.h>
#include <event.h>

using namespace Shuanglong::Utils;
using namespace Shuanglong::EventLoop;

static sighandler_t oldSignalHandler = SIG_ERR;
static MainLoop gMainLoop;

void InitializeSignalHandler();
void UninitializeSignalHandler();
void SignalHandler(int sigNum);
void SignalActionHandler(int sigNum, siginfo_t *pSigInfo, void *pSigValue);

int TimerCreate(timer_t *pOutTimerID, int intervalSeconds, int startSeconds);
int TimerSetTime(timer_t timerID, int intervalSeconds, int startSeconds);
int TimerDelete(timer_t timerID);

void ShowDescription();
void ShowSignalInfoCode();

int main(int argc, char *argv[])
{
    // 模拟发送信号
    if (argc >= 3)
    {
        int pid = atoi(argv[1]);
        int sigNum = atoi(argv[2]);
        //kill(pid, sigNum);

        int sigValue = 0;
        if (argc >= 4)
        {
            sigValue = atoi(argv[3]);
        }
        union sigval sig;
        sig.sival_int = sigValue;
        sigqueue(pid, sigNum, sig);
    }

    ShowDescription();
    ShowSignalInfoCode();
    
    Shuanglong::Application app;
    
    LogUtil::Debug(CODE_LOCATION, "getpid id : %d", getpid());
    LogUtil::Debug(CODE_LOCATION, "gettid id : %ld", gettid());
    LogUtil::Debug(CODE_LOCATION, "pthread_self id : %lu", pthread_self());
    LogUtil::Debug(CODE_LOCATION, "pthread_self id : 0x%lX", pthread_self());
    std::ostringstream sstring;
    sstring << std::this_thread::get_id();
    LogUtil::Debug(CODE_LOCATION, "std::this_thread::get_id id : %s", sstring.str().c_str());

    InitializeSignalHandler();
    
    int resultCode = app.Run(argc, argv);
    int res = 0;

    // 定时器测试
    alarm(2); // 如果想要重复触发，需在处理函数中再次调用 alarm(2)。
    struct itimerval timerValue;
    memset(&timerValue, 0, sizeof(timerValue));
    timerValue.it_value.tv_sec = 5; // 只响应一次超时
    // timerValue.it_interval.tv_sec = 1; // 多次超时响应
    res = setitimer(ITIMER_REAL, &timerValue, NULL);
    if (res == 0)
    {
        LogUtil::Debug(CODE_LOCATION, "settimer successfully!");
    }
    else
    {
        LogUtil::Debug(CODE_LOCATION, "settimer failed! [errno=%d] %s", errno, strerror(errno));
    }
    // POSIX 定时器测试
    timer_t timerID = 0;
    res = TimerCreate(&timerID, 5, 5);
    if (res != 0)
    {
        LogUtil::Debug(CODE_LOCATION, "TimerCreate failed! [errno=%d] %s", errno, strerror(errno));
    }

    // 子线程中运行 libevent 事件循环
    gMainLoop.Start();

    res = TimerDelete(timerID);
    if (res != 0)
    {
        LogUtil::Debug(CODE_LOCATION, "TimerDelete failed! [errno=%d] %s", errno, strerror(errno));
    }
    UninitializeSignalHandler();

    LogUtil::Info(CODE_LOCATION, "==================== will exiting with ExitCode:%d", resultCode);
    return resultCode;
}

void InitializeSignalHandler()
{
    oldSignalHandler = signal(SIGIO, SignalHandler);
    LogUtil::Debug(CODE_LOCATION, "oldSignalHandler = 0x%p", oldSignalHandler);
    oldSignalHandler = signal(SIGINT, SignalHandler);
    LogUtil::Debug(CODE_LOCATION, "oldSignalHandler = 0x%p", oldSignalHandler);
    oldSignalHandler = signal(SIGUSR1, SignalHandler);
    LogUtil::Debug(CODE_LOCATION, "oldSignalHandler = 0x%p", oldSignalHandler);
    oldSignalHandler = signal(SIGUSR2, SignalHandler);
    LogUtil::Debug(CODE_LOCATION, "oldSignalHandler = 0x%p", oldSignalHandler);
    oldSignalHandler = signal(SIGALRM, SignalHandler);
    LogUtil::Debug(CODE_LOCATION, "oldSignalHandler = 0x%p", oldSignalHandler);

    // 不能被捕获的信号
    oldSignalHandler = signal(SIGKILL, SignalHandler);
    if (oldSignalHandler == SIG_ERR)
    {
        LogUtil::Debug(CODE_LOCATION, "Set SIGKILL handler failed: [errno=%d] %s", errno, strerror(errno));
    }

    //return;

    // sigaction 测试
    struct sigaction sigact;
    sigact.sa_sigaction = SignalActionHandler;
    sigact.sa_flags = SA_SIGINFO;
    sigemptyset(&sigact.sa_mask);
    sigaction(SIGIO, &sigact, NULL);
    sigaction(SIGINT, &sigact, NULL);
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGUSR2, &sigact, NULL);
    sigaction(SIGKILL, &sigact, NULL);
    sigaction(SIGALRM, &sigact, NULL);
}

void UninitializeSignalHandler()
{
    signal(SIGIO, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    signal(SIGUSR1, SIG_DFL);
    signal(SIGUSR2, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    signal(SIGKILL, SIG_DFL);
}

void SignalHandler(int sigNum)
{
    switch (sigNum)
    {
        case SIGIO:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGIO");
            break;
        case SIGINT:
            gMainLoop.Stop();
            LogUtil::Debug(CODE_LOCATION, "Signal SIGINT");
            break;
        case SIGKILL:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGKILL");
            break;
        case SIGUSR1:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGUSR1");
            break;
        case SIGUSR2:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGUSR2");
            break;
        case SIGALRM:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGALRM CurrentTime: %s", TimeUtil::CurrentTimestampString().c_str());
            //alarm(2);
            break;
        default:
            LogUtil::Debug(CODE_LOCATION, "Unknown signal number");
            break;
    }
}

void SignalActionHandler(int sigNum, siginfo_t *pSigInfo, void *pSigValue)
{
    static bool swichTimerState = true;
    static timer_t timerID = 0;
    int sigInt = pSigInfo->si_int;

    /*
    int res = 0;
    struct timeval changeTimeOfDay;
    changeTimeOfDay.tv_sec = 88899L;
    changeTimeOfDay.tv_usec = 0L;
    struct timezone changeTimeZone;
    */

    switch (sigNum)
    {
        case SIGIO:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGIO sigint:%d", sigInt);
            break;
        case SIGINT:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGINT sigint:%d", sigInt);
            gMainLoop.Stop();
            break;
        case SIGKILL:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGKILL sigint:%d", sigInt);
            break;
        case SIGUSR1:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGUSR1 sigint:%d", sigInt);
            if (swichTimerState)
            {
                TimerSetTime(timerID, 0, 0);
            }
            else
            {
                TimerSetTime(timerID, 5, 5);
            }
            swichTimerState = !swichTimerState;
            /*
            res = settimeofday(&changeTimeOfDay, NULL);
            if (res == 0)
            {
                LogUtil::Debug(CODE_LOCATION, "settimeofday successfully!");
            }
            else
            {
                LogUtil::Debug(CODE_LOCATION, "settimeofday failed! errno=%d %s", errno, strerror(errno));
            }
            */
            break;
        case SIGUSR2:
            if (pSigInfo->si_code == SI_TIMER)
            {
                if (pSigInfo->si_ptr)
                {
                    timerID = *(timer_t*)pSigInfo->si_ptr;
                }
                LogUtil::Info(CODE_LOCATION, "Receive SIGUSR2 CurrentTime:%s TimerID:%llu  gettid=%ld  pthread_self=%lu",
                        TimeUtil::CurrentTimestampString().c_str(), timerID, gettid(), pthread_self());

                sigset_t pendingSigSet;
                sigemptyset(&pendingSigSet);
                sigpending(&pendingSigSet);
                if (!sigisemptyset(&pendingSigSet))
                {
                    for (int i=1; i<_NSIG; i++)
                    {
                        if (sigismember(&pendingSigSet, i))
                        {
                            LogUtil::Warn(CODE_LOCATION, "There are some signals suspending %d", i);
                        }
                    }
                }
            }
            else
            {
                LogUtil::Warn(CODE_LOCATION, "Receive SIGUSR2 but not timer emit it. pid=%d si_code=%d",
                        pSigInfo->si_pid, pSigInfo->si_code);
            }
            break;
        case SIGALRM:
            LogUtil::Debug(CODE_LOCATION, "Receive SIGALRM sigint:%d CurrentTime:%s",
                    sigInt, TimeUtil::CurrentTimestampString().c_str());
            // alarm(2);
            break;
        default:
            LogUtil::Debug(CODE_LOCATION, "Unknown signal number");
            break;
    }
}

/*
 * intervalSeconds 定时器超时时间间隔，该值为 0 时，定时器只触发一次，取决于 startSeconds。
 * startSeconds 首次超时时间，该值为 0 时，定时器无效，永远不会触发超时。
 * */
int TimerCreate(timer_t *pOutTimerID, int intervalSeconds, int startSeconds)
{
    int result = 0;
    timer_t timerID = 0;
    struct sigevent timerEvent = {0};
    timerEvent.sigev_value.sival_ptr = pOutTimerID;
    timerEvent.sigev_notify = SIGEV_SIGNAL;
    timerEvent.sigev_signo = SIGNAL_TIMER;
    
    result = timer_create(CLOCK_REALTIME, &timerEvent, &timerID);
    if (result == 0)
    {
        if (pOutTimerID != NULL)
        {
            *pOutTimerID = timerID;
        }
        result = TimerSetTime(timerID, intervalSeconds, startSeconds);
    }
    else
    {
        LogUtil::Info(CODE_LOCATION, "timer_create failed! [errno=%d] %s", errno, strerror(errno));
    }

    return result;
}

int TimerSetTime(timer_t timerID, int intervalSeconds, int startSeconds)
{
    int result = 0;

    struct itimerspec timerInterval = { 0 };
    timerInterval.it_interval.tv_sec = intervalSeconds;
    timerInterval.it_value.tv_sec = startSeconds;
    result = timer_settime(timerID, 0, &timerInterval, NULL);
    if (result != 0)
    {
        LogUtil::Info(CODE_LOCATION, "timer_settime failed! timerID=%d [errno=%d] %s",
                timerID, errno, strerror(errno));
    }

    return result;
}

int TimerDelete(timer_t timerID)
{
    return timer_delete(timerID);
}

void ShowDescription()
{
    // sudo apt install figlet
    // figlet -f slant shuanglong

    std::cout << "         __                            __                  " << std::endl;
    std::cout << "   _____/ /_  __  ______ _____  ____ _/ /___  ____  ____ _ " << std::endl;
    std::cout << "  / ___/ __ \\/ / / / __ `/ __ \\/ __ `/ / __ \\/ __ \\/ __ `/ " << std::endl;
    std::cout << " (__  ) / / / /_/ / /_/ / / / / /_/ / / /_/ / / / / /_/ /  " << std::endl;
    std::cout << "/____/_/ /_/\\__,_/\\__,_/_/ /_/\\__, /_/\\____/_/ /_/\\__, /   " << std::endl;
    std::cout << "                             /____/              /____/    " << std::endl;
}

void ShowSignalInfoCode()
{
    LogUtil::Info(CODE_LOCATION, "SI_ASYNCNL  = %d", SI_ASYNCNL);
    LogUtil::Info(CODE_LOCATION, "SI_TKILL    = %d", SI_TKILL);
    LogUtil::Info(CODE_LOCATION, "SI_SIGIO    = %d", SI_SIGIO);
    LogUtil::Info(CODE_LOCATION, "SI_ASYNCIO  = %d", SI_ASYNCIO);
    LogUtil::Info(CODE_LOCATION, "SI_MESGQ    = %d", SI_MESGQ);
    LogUtil::Info(CODE_LOCATION, "SI_TIMER    = %d", SI_TIMER);
    LogUtil::Info(CODE_LOCATION, "SI_QUEUE    = %d", SI_QUEUE);
    LogUtil::Info(CODE_LOCATION, "SI_USER     = %d", SI_USER);
    LogUtil::Info(CODE_LOCATION, "SI_KERNEL   = %d", SI_KERNEL);
}

