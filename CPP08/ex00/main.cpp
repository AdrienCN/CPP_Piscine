#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <stdexcept>
/*
int		main()
{
	try
	{
		std::vector<int> intTab;
	
		std::cout << easyfind(intTab, 108) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
*/

void list_test()
{
	std::cout << "*** LIST ***" << std::endl;
	std::list<int> lst;
	
	for (int i = 1; i < 6; i++)
		lst.push_back(i*10);
	
	for (std::list<int>::const_iterator it = lst.begin(), end = lst.end();
			it != end; it++) 
		std::cout << *it << std::endl;
	
	std::cout << std::endl;

	try
   	{
		std::cout << "Find 10? : " << *easyfind<std::list<int> >(lst, 10) << std::endl;
		std::cout << "Find 20? : " << *easyfind<std::list<int> >(lst, 20) << std::endl;
		std::cout << "Find 30? : " << *easyfind<std::list<int> >(lst, 30) << std::endl;
		std::cout << "Find 40? : " << *easyfind<std::list<int> >(lst, 40) << std::endl;
		std::cout << "Find 50? : " << *easyfind<std::list<int> >(lst, 50) << std::endl;
	}
	catch (std::exception& e)
   	{
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	try
   	{
		std::cout << "Find 0? : " << *easyfind<std::list<int> >(lst, 0) << std::endl;
	}
	catch (std::exception& e)
   	{
		std::cout << e.what() << std::endl;
	}

	try
   	{
		std::cout << "Find -1? : " << *easyfind<std::list<int> >(lst, -1) << std::endl;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
   	{
		std::cout << "Find 9999? : " << *easyfind<std::list<int> >(lst, 9999) << std::endl;
	}
	catch (std::exception& e)
   	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl;
}

void vector_test()
{
	std::cout << "*** VECTOR ***" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i < 6; i++) {
		vec.push_back(i*10);
	}
	for (std::vector<int>::const_iterator it = vec.begin(), end = vec.end();
			it != end; it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	try
   	{	std::cout << "Find 10? : " << *easyfind<std::vector<int> >(vec, 10) << std::endl;
		std::cout << "Find 20? : " << *easyfind<std::vector<int> >(vec, 20) << std::endl;
		std::cout << "Find 30? : " << *easyfind<std::vector<int> >(vec, 30) << std::endl;
		std::cout << "Find 40? : " << *easyfind<std::vector<int> >(vec, 40) << std::endl;
		std::cout << "Find 50? : " << *easyfind<std::vector<int> >(vec, 50) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try
   	{
		std::cout << "Find 0? : " << *easyfind<std::vector<int> >(vec, 0) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
   	{
		std::cout << "Find -1? : " << *easyfind<std::vector<int> >(vec, -1) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
   	{
		std::cout << "Find 9999? : " << *easyfind<std::vector<int> >(vec, 9999) << std::endl;
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl;
}

int main()
{
	list_test();
	std::cout << std::endl;
	vector_test();
	return 0;
}
