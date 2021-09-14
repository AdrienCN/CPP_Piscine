#include "span.hpp"

#include <iostream>
#include <string>

int main ()
{
	try
	{
		int a = 10;
		Span sp(a + 1);
		sp.print_span();
		std::vector<int> vector(a, 42);

		sp.addNumber(vector.begin(), vector.end()); // iterator filling
		sp.addNumber(48);
		//uncomment  below to see error "SPAN IS FULL"
		//sp.addNumber(52); 
		std::cout << "sp : " ;
		sp.print_span();
		std::cout << "Shortestspan " << sp.shortestSpan() << std::endl;
		std::cout << "Longestspan " << sp.longestSpan() << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
