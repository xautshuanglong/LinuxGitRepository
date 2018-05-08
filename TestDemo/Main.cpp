#include "Common.h"
#include "Application.h"

#include "Utils/LogUtil.h"
using namespace Shuanglong::Utils; 
using namespace Shuanglong;

void ShowDescription();

int main(int argc, char *argv[])
{
    //ShowDescription();
    
    LogUtil::Debug(CODE_LOCATION, (char*)"Testing");

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

