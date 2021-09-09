#include <cstring>

#include "Array.hpp"

void int_array_tests()
{
	std::cout << "***INT***\n" << std::endl;
	
	Array<int> empty_array;
	std::cout << "Creation of an empty_array, with.getSize : " << empty_array.getSize() << std::endl;

	Array<int> int_array(4);
	std::cout << "\nCreation of an array of 4 elements by default :" << std::endl;
	for (unsigned int i = 0; i < int_array.getSize(); i++)
		std::cout << int_array[i] << std::endl;

	std::cout << "\nAssigning values i + 1 to this array" << std::endl;
	for (unsigned int i = 0; i < int_array.getSize(); i++)
	{
		int_array[i] = i + 1;
		std::cout << int_array[i] << std::endl;
	}
	std::cout << "\nTest copy constructor and assignement operator :" << std::endl;
	Array<int> other_int_array(int_array);
	std::cout << "Initial Array values" << std::endl;
	for (unsigned int i = 0; i < int_array.getSize(); i++)
		std::cout << int_array[i] << std::endl;
	std::cout << std::endl;
	
	std::cout << "New Array values" << std::endl;
	for (unsigned int i = 0; i < other_int_array.getSize(); i++)
		std::cout << other_int_array[i] << std::endl;
	
	std::cout << "\nModifying the new array -(i + 1)" << std::endl;
	for (unsigned int i = 0; i < other_int_array.getSize(); i++)
	{
		other_int_array[i] = -(i + 1);
		std::cout << other_int_array[i] << std::endl;
	}
	std::cout << "\nCheck that the first array is unchanged" << std::endl;
	for (unsigned int i = 0; i < int_array.getSize(); i++)
		std::cout << int_array[i] << std::endl;

	std::cout << "\n====> out of limits indexes tests <===" << std::endl;
	try
	{
		std::cout << "-1 index" << std::endl;
		std::cout << int_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try
	{
		std::cout << "4 index (array.getSize)" << std::endl;
		std::cout << int_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try
	{
		std::cout << "9999 index" << std::endl;
		std::cout << int_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	std::cout << "\n****************************************************************************\n" << std::endl;
}

void string_array_tests()
{
	std::string strings[4] = { "abc", "def ", "ghi", "jkl"};
	std::string other_strings[4] = { "ABC", "DEF", "GHI", "JKL"};
	
	std::cout << "***STRING***\n" << std::endl;
	Array<std::string> empty_array;
	std::cout << "Creation of an empty_array, with.getSize : " << empty_array.getSize() << std::endl;

	Array<std::string> string_array(4);
	std::cout << "\nCreation of an array of 4 elements by default :" << std::endl;
	for (unsigned int i = 0; i < string_array.getSize(); i++)
		std::cout << string_array[i] << std::endl;

	std::cout << "\nAssigning values to this array" << std::endl;
	for (unsigned int i = 0; i < string_array.getSize(); i++)
	{
		string_array[i] = strings[i];
		std::cout << string_array[i] << std::endl;
	}
	
	std::cout << "\nTest constructor and assignement operator :" << std::endl;
	Array<std::string> other_string_array(string_array);
	std::cout << "Initial Array values" << std::endl;
	for (unsigned int i = 0; i < string_array.getSize(); i++)
		std::cout << string_array[i] << std::endl;
	std::cout << std::endl;
	
	std::cout << "New Array values" << std::endl;
	for (unsigned int i = 0; i < other_string_array.getSize(); i++)
		std::cout << other_string_array[i] << std::endl;
	
	std::cout << "\nModifying the new array" << std::endl;
	for (unsigned int i = 0; i < other_string_array.getSize(); i++)
	{
		other_string_array[i] = other_strings[i];
		std::cout << other_string_array[i] << std::endl;
	}

	std::cout << "\nCheck that the first array is unchanged" << std::endl;
	for (unsigned int i = 0; i < string_array.getSize(); i++) 
		std::cout << string_array[i] << std::endl;

	std::cout << "\n====> out of limits indexes tests <===" << std::endl;
	try
	{
		std::cout << "-1 index" << std::endl;
		std::cout << string_array[-1] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try
	{
		std::cout << "4 index (array.getSize)" << std::endl;
		std::cout << string_array[4] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	try
	{
		std::cout << "9999 index" << std::endl;
		std::cout << string_array[9999] << " SHOULD NOT BE DISPLAYED" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught message: \"" << e.what() << "\""
			<< std::endl;
	}
	std::cout << "\n****************************************************************************\n" << std::endl;
}

int main()
{
	int_array_tests();
	string_array_tests();
}
