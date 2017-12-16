#include "Common.h"

#include "Utils/StringUtil.h"
#include "Utils/LogUtil.h"

void ShowDescription();

int main(int argc, char **argv)
{
    std::cout << "======================= Main ======================" <<std::endl;

    Shuanglong::Utils::StringUtil str;
    Shuanglong::Utils::LogUtil log;
    
    // CodeLocation Testing
    std::cout << "CODE_LOCATION_STRING = " << CODE_LOCATION_STRING << std::endl;

    ShowDescription();

    std::cout << "Func:" << __FUNCTION__ << "  at " << __FILE__ << ":" << __LINE__ << std::endl; 

    std::cout << "Before return 0" << std::endl;

    return 0;
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
    std::cout << "                                                            \\  '-'  /                                   \\  '-'  /   " << std::endl;
    std::cout << "                                                             '-----'                                     '-----'    " << std::endl;
}

