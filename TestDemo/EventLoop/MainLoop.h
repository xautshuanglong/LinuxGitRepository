#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

#include <pthread.h>

struct event;
struct event_base;
struct timeval;

namespace Shuanglong::EventLoop
{
    class MainLoop
    {
        public:
            MainLoop();
            ~MainLoop();

            void Start();
            void Stop();

            void* Run();
            void TimerEventHandler();

        private:
            static void* ThreadStartRoutine(void *pArguement);
            static void EventCallback(int fd, short event, void *pArgument);

        private:
            pthread_t          mEventThread;
            struct event_base *mpEventBase;
            struct event      *mpEventTimer;
            struct timeval    *mpTimeValue;
    };
}

#endif // _MAIN_LOOP_H_

