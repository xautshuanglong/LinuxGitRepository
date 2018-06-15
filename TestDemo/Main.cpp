#include "Common.h"
#include "Application.h"

void ShowDescription();

int main(int argc, char *argv[])
{
//    ShowDescription();
    
    Shuanglong::Application app;
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

