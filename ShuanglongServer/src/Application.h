#ifndef APPLICATION_H
#define APPLICATION_H

namespace Shuanglong
{
    class Application
    {
        private:
            int     mIntValue;

        public:
            Application();
            ~Application();

            int Run(int argc, char* argv[]);
    };
}

#endif // APPLICATION_H
