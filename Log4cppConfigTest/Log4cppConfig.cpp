#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/NDC.hh>
#include <log4cpp/PropertyConfigurator.hh>

using namespace std;
using namespace log4cpp;

int main(int argc, char* argv[])
{
    try
    {
        PropertyConfigurator::configure(".//config//log4cpp.init");
    }
    catch (ConfigureFailure& e)
    {
        cout << "Configure Problem: " << e.what() << endl;
        return -1;
    }

    Category& root = Category::getRoot();
    Category& sub1 = Category::getInstance("file");
    Category& sub2 = Category::getInstance("rolling");

    NDC::push("Log4cppConfigTest");

    root.info("root info testing");
    root.debug("root debug testing");
    root.warn("root warn testing");
    root.error("root error testing");

    sub1.info("sub1 info testing");
    sub1.debug("sub1 debug testing");
    sub1.warn("sub1 warn testing");
    sub1.error("sub1 error testing");

    sub2.info("sub2 info testing");
    sub2.debug("sub2 debug testing");
    sub2.warn("sub2 warn testing");
    sub2.error("sub2 error testing");

    return 0;
}
