#include "Zipper.h"

int main()
{
	Zipper zipper;

	char operationCode;

	std::string fileName;
	
	std::cout << "Enter operation code: d/c" << std::endl;
	std::cin >> operationCode;
	
	if(operationCode == 'd' || operationCode == 'c')
	{
		std::cout << "Enter file name: " << std::endl;
		std::cin >> fileName;

		if(operationCode == 'd')
		{
			zipper.decompress(fileName);
		}
		else
		{
			zipper.compress(fileName);
		}
	}
	else
	{
		std::cout << "Invalid operation code.Terminating... " << std::endl;
	}

	return 0;
}
