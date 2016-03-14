#include <iostream>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/BasicConfigurator.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;

int main()
{
    std::cout<<"test.cpp"<<std::endl;
	log4cpp::BasicConfigurator::configure();
	log4cpp::Category::shutdown();

    return 0;
}
