#ifndef APPLICATION_H
#define APPLICATION_H

namespace Shuanglong
{
    class Application
    {
        public:
            Application();
            ~Application();

            int Run(int argc, char *argv[]);
        private:
            void PrintArguments(int argc, char *argv[]);
    };
}

#endif

