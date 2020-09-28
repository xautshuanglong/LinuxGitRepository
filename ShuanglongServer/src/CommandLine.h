#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <string>

namespace Shuanglong
{
    class CommandLine
    {
        public:
            CommandLine();
            ~CommandLine();

            bool ParseCommandArguments(int argc, char **argv);

        private:
            std::string   mStrCmdArgs;
    };
}

#endif // COMMAND_LINE_H

