#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <exception>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <map>


namespace EasyFindException
{
		class OutOfRange : public std::exception 
		{
			public:
				virtual const char * what(void) const throw()
				{
					return "Exception Caught : Element not found in container";
				}
		};
		class Empty : public std::exception
		{
			public:
				virtual const char * what(void) const throw()
				{
					return "Exception Caught: Container is empty";
				}
		};
};

template<typename T>
typename T::const_iterator easyfind(T const & container, int const target)
{
	typename T::const_iterator it;

	if (container.empty() == true)
		throw EasyFindException::Empty();

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw EasyFindException::OutOfRange();
	else
		return it;
}


#endif
