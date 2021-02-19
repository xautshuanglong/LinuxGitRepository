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
    
    printf("getpid id : %d\n", getpid());
    printf("gettid id : %ld\n", gettid());
    printf("pthread_self id : %lu\n", pthread_self());
    printf("pthread_self id : 0x%lX\n", pthread_self());
    std::cout << "std::this_thread::get_id id : " << std::this_thread::get_id() << std::endl;

    struct pthread *pThreadSelf = (struct pthread *)pthread_self();
    //printf("pthread_self tid: %d\n", pThreadSelf->tid);

    InitializeSignalHandler();
    
    int resultCode = app.Run(argc, argv);

    alarm(2);

    while (gLoopFlag)
    {
        sleep(100);
    }

    UninitializeSignalHandler();

    std::cout << "will exiting with ExitCode:" << resultCode << std::endl;
    return resultCode;
}

void InitializeSignalHandler()
{
    oldSignalHandler = signal(SIGIO, SignalHandler);
    printf("oldSignalHandler = 0x%p\n", oldSignalHandler);
    oldSignalHandler = signal(SIGINT, SignalHandler);
    printf("oldSignalHandler = 0x%p\n", oldSignalHandler);
    oldSignalHandler = signal(SIGUSR1, SignalHandler);
    printf("oldSignalHandler = 0x%p\n", oldSignalHandler);
    oldSignalHandler = signal(SIGALRM, SignalHandler);
    printf("oldSignalHandler = 0x%p\n", oldSignalHandler);

    // 不能被捕获的信号
    oldSignalHandler = signal(SIGKILL, SignalHandler);
    if (oldSignalHandler == SIG_ERR)
    {
        printf("Set SIGKILL handler failed: [errno=%d] %s\n", errno, strerror(errno));
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
            printf("Signal SIGIO SignalHandler Main.cpp\n");
            break;
        case SIGINT:
            gLoopFlag = false;
            printf("Signal SIGINT SignalHandler Main.cpp\n");
            break;
        case SIGKILL:
            printf("Signal SIGKILL SignalHandler Main.cpp\n");
            break;
        case SIGUSR1:
            printf("Signal SIGUSR1 SignalHandler Main.cpp\n");
            break;
        case SIGALRM:
            printf("Signal SIGALRM CurrentTime:%lld SignalHandler Main.cpp\n", TimeUtil::CurrentSecondsFromEpoch());
            alarm(2);
            break;
        default:
            printf("Unknown signal number SignalHandler Main.cpp\n");
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
            printf("SignalAction SIGIO sigint:%d sigval:%d SignalActionHandler Main.cpp\n", sigInt, sigValue);
            break;
        case SIGINT:
            gLoopFlag = false;
            printf("SignalAction SIGINT sigint:%d sigval:%d SignalActionHandler Main.cpp\n", sigInt, sigValue);
            break;
        case SIGKILL:
            printf("SignalAction SIGKILL sigint:%d sigval:%d SignalActionHandler Main.cpp\n", sigInt, sigValue);
            break;
        case SIGUSR1:
            printf("SignalAction SIGUSR1 sigint:%d sigval:%d SignalActionHandler Main.cpp\n", sigInt, sigValue);
            /*
            res = settimeofday(&changeTimeOfDay, NULL);
            if (res == 0)
            {
                printf("settimeofday successfully!\n");
            }
            else
            {
                printf("settimeofday failed! errno=%d %s\n", errno, strerror(errno));
            }
            */
            break;
        case SIGALRM:
            printf("SignalAction SIGALRM sigint:%d sigval:%d CurrentTime:%lld SignalActionHandler Main.cpp\n",
                    sigInt, sigValue, TimeUtil::CurrentSecondsFromEpoch());
            // alarm(2);
            break;
        default:
            printf("Unknown signal number SignalActionHandler Main.cpp\n");
            break;
    }
    printf("gettid id : %ld\n", gettid());
    printf("pthread_self id : %lu\n", pthread_self());
    std::cout << "std::this_thread::get_id id : " << std::this_thread::get_id() << std::endl;
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

