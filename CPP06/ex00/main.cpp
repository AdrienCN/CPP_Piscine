#include "Convert.hpp"

int		main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "Error : [Convertor] only works with one argument" << std::endl;
			return 1;
		}
		Convert convertor(argv[1]);
		convertor.convert_data();
	}
	catch(const std::invalid_argument & ia)
	{
		std::cout << "Error : MAIN : " << ia.what() << std::endl;
	}
		return 0;
}
