#include "Common.h"

#include <vector>

#include "Utils/StringUtil.h"
#include "Utils/LogUtil.h"
#include "Utils/EnvUtil.h"

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
    std::cout << "Endian big = " << Shuanglong::Utils::EnvUtil::IsEndianBig() << std::endl;
    std::cout << "Endian little = " << Shuanglong::Utils::EnvUtil::IsEndianLittle() << std::endl;

    std::cout << "Before return 0" << std::endl;

    std::vector<int> intVec = {1, 2, 3, 4, 5};
    for (int var : intVec)
    {
        std::cout << "var = " << var << std::endl;
    }

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
    std::cout << "                                                            \\  '-'   /                                  \\  '-'   /  " << std::endl;
    std::cout << "                                                             '------'                                    '------'   " << std::endl;
}

