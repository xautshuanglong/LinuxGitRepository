#include "Common.h"
#include "Application.h"
#include <string.h>

using namespace Shuanglong;

void ShowDescription();

int main(int argc, char *argv[])
{
    //ShowDescription();

    Application app;
    return app.Run(argc, argv);
}

void ShowDescription()
{
    std::cout << "  .--------. .--.                                                      .--.                                         " << std::endl;
    std::cout << " /  .---.  : |  |                                                      |  |                                         " << std::endl;
    std::cout << " |  |   '--' |  |                                                      |  |                                         " << std::endl;
    std::cout << " \\  '-----.  |  '------. .--.   .--.   .----.     .-----.    .------.  |  |        .----.     .-----.    .------.   " << std::endl;
    std::cout << "  '----.   ' |  .---.  | |  |   |  |  /  __  \\   /  .-.  \\  /   __   \\ |  |       /  __  \\   /  .-.  \\  /   __   \\  " << std::endl;
    std::cout << "        |  | |  |   |  | |  |   |  | |  /  \\  | |  /   \\  | |  /  \\  | |  |      |  /  \\  | |  /   \\  | |  /  \\  |  " << std::endl; 
    std::cout << " .--.   |  | |  |   |  | |  |   |  | |  \\__/  | |  |   |  | |  \\__/  | |  |      |  \\__/  | |  |   |  | |  \\__/  |  " << std::endl; 
    std::cout << " :  '---'  ; |  |   |  | |  '---'  |  \\       | |  |   |  | \\        | |  '-----. \\      /  |  |   |  | \\        |  " << std::endl; 
    std::cout << "  '-------'  '--'   '--' '------'--'   '----'-' '--'   '--'  '----|  | '--------'  '----'   '--'   '--'  '----|  |  " << std::endl; 
    std::cout << "                                                                  |  |                                        |  |  " << std::endl; 
    std::cout << "                                                            .-.   ;  |                                  .-.   ;  |  " << std::endl;
    std::cout << "                                                            \\  '-'   /                                  \\  '-'   /  " << std::endl;
    std::cout << "                                                             '------'                                    '------'   " << std::endl;
}

