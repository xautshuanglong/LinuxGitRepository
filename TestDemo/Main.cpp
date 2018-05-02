#include "Common.h"

#include <vector>

#include "Utils/StringUtil.h"
#include "Utils/LogUtil.h"

int main(int argc, char **argv)
{
    std::cout << "======================= Main ======================" <<std::endl;

    Shuanglong::Utils::StringUtil str;
    Shuanglong::Utils::LogUtil log;

    std::cout << "Before return 0" << __FILE__ << std::endl;

    std::vector<int> intVec = {1, 2, 3, 4, 5};
    for (int var : intVec)
    {
        std::cout << "var = " << var << std::endl;
    }

    return 0;
}

