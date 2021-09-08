#include "Convert.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : [Convertor] only works with one argument" << std::endl;
		return 1;
	}
	Convert convertor(argv[1]);
	convertor.convert_data();
	return 0;
}
