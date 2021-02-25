#ifndef _MAIN_LOOP_H_
#define _MAIN_LOOP_H_

namespace Shuanglong::EventLoop
{
    class MainLoop
    {
        public:
            MainLoop();
            ~MainLoop();

            void Start();
            void Stop();
            static void* ThreadRoutine(void *pArguement);

        private:
            void SetValue(int value);

        private:
            volatile bool mRunningFlag;
            int mValue;
    };
}

#endif // _MAIN_LOOP_H_

