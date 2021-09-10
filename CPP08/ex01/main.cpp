#include "span.hpp"

#include <iostream>
#include <string>

int main ()
{
	try
	{
		Span sp(5);
		Span a(10);
		std::vector<int> b(10, 42);

		a.addNumber(b.begin(), b.end());
		std::cout << "a : " ;
		a.print_span();
		sp.print_span();
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.print_span();

		std::cout << "Bis ";
		Span sp_bis(sp);
		
		std::cout << "Bis ";
		sp_bis.print_span();
		sp_bis.addNumber(9);
		std::cout << "Bis ";
		sp_bis.print_span();
		
		sp = sp_bis;
		std::cout << "Original ";
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
