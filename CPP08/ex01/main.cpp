#include "span.hpp"

#include <iostream>
#include <string>

int main ()
{
	try
	{
		int a = 1000000;
		Span sp(a + 1);
		std::vector<int> b(a, 42);

		sp.addNumber(b.begin(), b.end());
		sp.addNumber(48);
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
