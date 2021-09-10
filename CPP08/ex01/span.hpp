#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath> //absolute val
#include <climits>
#include <algorithm>
#include <stdexcept>

class Span
{

	public :

		class Empty_Or_Single : public std::exception
		{
			public:
				virtual  const char* what(void) const throw()
				{
					return "Exception : Span : Container is EMPTY or has ONE data only";
				}
		};

		class Already_Full : public std::exception
		{
			public:
			virtual const char * what(void) const throw()
			{
				return "Exception : Span : Container is already FULL";
			}
		};

		Span(unsigned int N);
		Span(Span const & src);
		Span & operator=(Span const & src);

		~Span();
		
		void	addNumber(int const & newNb);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			print_span();

			


	private:
		Span();
		std::vector<int> _intTab;
		unsigned int	 _max_size;
};

#endif
