#include <iostream>

int main(int argc,char** argv)
{
	std::cout << "count of arguments:" << argc << std::endl;

	int i = 0;
	for(i=0; i<argc; i++)
	{
		std::cout << "argv[" << i << "]   " << *(argv+i) << std::endl;
	}

	return 0;
}
