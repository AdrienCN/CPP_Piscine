#include "Base.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <exception>

Base * generate(void)
{
	srand(time(NULL));
	
	int i;

	i = rand() % 3;
//	std::cout << "i = " << i << std::endl;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	std::cout << "Pointer : ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error : Could not identify object" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Reference : ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			try 
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch(...)
			{
				std::cerr << "Error : Could not identify object (reference)" << std::endl;
			}
		}
	}
}

int		main(void)
{
	Base  *ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
