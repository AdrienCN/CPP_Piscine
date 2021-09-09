#include "iter.hpp"
#include <iostream>
#include <string>

int		main()
{
	int				intTab[3] = {0, 1, 2};
	std::string		strTab[3] = {"Riri", "Fifi", "Loulou"};	

	iter(intTab, 3, &display);
	
	std::cout << std::endl;
	
	iter(strTab, 3, &display);
	
	return (0);
}
