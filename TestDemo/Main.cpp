#include "Common.h"
#include "Application.h"

void ShowDescription();

int main(int argc, char *argv[])
{
    ShowDescription();
    
    Shuanglong::Application app;
    return app.Run(argc, argv);
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

