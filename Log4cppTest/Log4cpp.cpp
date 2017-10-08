#include <iostream>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/BasicConfigurator.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;
using namespace log4cpp;

int main(int argc, char* argv[])
{
    cout<< argv[0] << endl;

    inr gitTest=0;//test

    BasicConfigurator::configure();
    PatternLayout* layout = new PatternLayout();
    Category::getRoot().getAppender()->setLayout(layout);
    Category& cat = Category::getInstance("cat1");

    layout->setConversionPattern("%d{%Y-%m-%d %H:%M:%S.%l} [%-5p] %c %m%n");

    cat.setPriority(Priority::DEBUG);

    cat.info("info testing");
    cat.debug("debug testing");
    cat.error("debug testing");
    cat.fatal("debug testing");
    cat.warn("debug testing");
    cat.emerg("debug testing");

    Category::shutdown();

    return 0;
}
