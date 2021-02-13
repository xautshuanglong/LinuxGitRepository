#include "Common.h"
#include "Application.h"

#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <pthread.h>
#include <thread>

#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)

static bool gLoopFlag = true;
static sighandler_t oldSignalHandler = SIG_ERR;

void InitializeSignalHandler();
void UninitializeSignalHandler();
void SignalHandler(int sigNum);

void ShowDescription();

int main(int argc, char *argv[])
{
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

    while (gLoopFlag)
    {
        sleep(100);
    }

    UninitializeSignalHandler();

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

    // 不能被捕获的信号
    oldSignalHandler = signal(SIGKILL, SignalHandler);
    if (oldSignalHandler == SIG_ERR)
    {
        printf("Set SIGKILL handler failed: [errno=%d] %s\n", errno, strerror(errno));
    }
}

void UninitializeSignalHandler()
{}

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
        default:
            printf("Unknown signal number SignalHandler Main.cpp\n");
            break;
    }
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

