#include "Common.h"
#include "Application.h"

#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <pthread.h>
#include <thread>

#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)

#include "Utils/TimeUtil.h"
using namespace Shuanglong::Utils;

static bool gLoopFlag = true;
static sighandler_t oldSignalHandler = SIG_ERR;

void InitializeSignalHandler();
void UninitializeSignalHandler();
void SignalHandler(int sigNum);
void SignalActionHandler(int sigNum, siginfo_t *pSigInfo, void *pSigValue);

void ShowDescription();

int main(int argc, char *argv[])
{
    // 模拟发送信号
    if (argc >= 3)
    {
        gLoopFlag = false;
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
    
    Shuanglong::Application app;
    
    LogUtil::Debug(CODE_LOCATION, "getpid id : %d", getpid());
    LogUtil::Debug(CODE_LOCATION, "gettid id : %ld", gettid());
    LogUtil::Debug(CODE_LOCATION, "pthread_self id : %lu", pthread_self());
    LogUtil::Debug(CODE_LOCATION, "pthread_self id : 0x%lX", pthread_self());
    std::ostringstream sstring;
    sstring << std::this_thread::get_id();
    LogUtil::Debug(CODE_LOCATION, "std::this_thread::get_id id : %s", sstring.str().c_str());

    struct pthread *pThreadSelf = (struct pthread *)pthread_self();
    //LogUtil::Debug(CODE_LOCATION, "pthread_self tid: %d", pThreadSelf->tid);

    InitializeSignalHandler();
    
    int resultCode = app.Run(argc, argv);

    // 定时器测试
    alarm(2); // 如果想要重复触发，需在处理函数中再次调用 alarm(2)。
    struct itimerval timerValue;
    memset(&timerValue, 0, sizeof(timerValue));
    timerValue.it_value.tv_sec = 5;
    timerValue.it_value.tv_usec = 0;
    int res = setitimer(ITIMER_REAL, &timerValue, NULL);
    if (res == 0)
    {
        LogUtil::Debug(CODE_LOCATION, "settimer successfully!");
    }
    else
    {
        LogUtil::Debug(CODE_LOCATION, "settimer failed! [errno=%d] %s", errno, strerror(errno));
    }

    while (gLoopFlag)
    {
        sleep(100);
    }

    UninitializeSignalHandler();

    LogUtil::Debug(CODE_LOCATION, "==================== will exiting with ExitCode:%d", resultCode);
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
    sigaction(SIGIO, &sigact, NULL);
    sigaction(SIGINT, &sigact, NULL);
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGKILL, &sigact, NULL);
    sigaction(SIGALRM, &sigact, NULL);
}

void UninitializeSignalHandler()
{
    signal(SIGIO, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    signal(SIGUSR1, SIG_DFL);
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
            gLoopFlag = false;
            LogUtil::Debug(CODE_LOCATION, "Signal SIGINT");
            break;
        case SIGKILL:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGKILL");
            break;
        case SIGUSR1:
            LogUtil::Debug(CODE_LOCATION, "Signal SIGUSR1");
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
    int sigInt = pSigInfo->si_int;
    int sigValue = pSigInfo->si_value.sival_int;

    int res = 0;
    struct timeval changeTimeOfDay;
    changeTimeOfDay.tv_sec = 88899L;
    changeTimeOfDay.tv_usec = 0L;
    struct timezone changeTimeZone;

    switch (sigNum)
    {
        case SIGIO:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGIO sigint:%d sigval:%dp", sigInt, sigValue);
            break;
        case SIGINT:
            gLoopFlag = false;
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGINT sigint:%d sigval:%d", sigInt, sigValue);
            break;
        case SIGKILL:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGKILL sigint:%d sigval:%d", sigInt, sigValue);
            break;
        case SIGUSR1:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGUSR1 sigint:%d sigval:%d", sigInt, sigValue);
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
        case SIGALRM:
            LogUtil::Debug(CODE_LOCATION, "SignalAction SIGALRM sigint:%d sigval:%d CurrentTime:%s",
                    sigInt, sigValue, TimeUtil::CurrentTimestampString().c_str());
            // alarm(2);
            break;
        default:
            LogUtil::Debug(CODE_LOCATION, "Unknown signal number");
            break;
    }
    std::ostringstream sstring;
    sstring << std::this_thread::get_id();
    LogUtil::Debug(CODE_LOCATION, "gettid id : %ld", gettid());
    LogUtil::Debug(CODE_LOCATION, "pthread_self id : %lu", pthread_self());
    LogUtil::Debug(CODE_LOCATION, "std::this_thread::get_id id : %s", sstring.str().c_str());
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

