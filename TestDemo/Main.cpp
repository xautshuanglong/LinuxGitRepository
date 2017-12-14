#include "Common.h"

#include "Utils/StringUtil.h"
#include "Utils/LogUtil.h"

int main(int argc, char **argv)
{
    std::cout << "======================= Main ======================" <<std::endl;

    Shuanglong::Utils::StringUtil str;
    Shuanglong::Utils::LogUtil log;

    std::cout << "Before return 0" << __FILE__ << std::endl;

    return 0;
}

