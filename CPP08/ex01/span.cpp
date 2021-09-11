#include "span.hpp"
#include <vector>

Span::Span()
{
}

Span::Span(unsigned int N) : _intTab(), _max_size(N)
{
}

Span::Span(Span const & src) : _intTab(src._intTab), _max_size(src._max_size)
{

}

Span & Span::operator=(Span const & src)
{
	_max_size = src._max_size;
	_intTab = src._intTab;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int const & newNb)
{
	if (_intTab.size() >= _max_size)
		throw Span::Already_Full();
	_intTab.push_back(newNb);
}


void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start != end)
	{
		addNumber(*start);
		start++;
	}
}


unsigned int Span::shortestSpan()
{
	if (_intTab.empty() || _intTab.size() <= 1)
		throw Span::Empty_Or_Single();

	std::vector<int>::iterator i = this->_intTab.begin();
	std::vector<int>::iterator j;
	unsigned int s_span;

	s_span = UINT_MAX;
	while (i != _intTab.end())
	{
		j = i + 1;
		unsigned int tmp;
		tmp = std::abs(*i - *j);
		if (tmp < s_span)
			s_span = tmp;
		i++;
	}
	return (s_span);
}

unsigned int Span::longestSpan()
{
	if (_intTab.empty() || _intTab.size() <= 1)
		throw Span::Empty_Or_Single();
	std::vector<int>::iterator first;
	std::vector<int>::iterator last;
	
	std::sort(_intTab.begin(), _intTab.end());
	
	first = _intTab.begin();
	last = _intTab.end() - 1;

	return (static_cast<unsigned int>(*last - *first));

}

void	Span::print_span()
{
	if (_intTab.empty())
	{
		std::cout << "Span : [Empty]" << std::endl;
		return;
	}
	std::cout << "Span : ";
	for (std::vector<int>::iterator i = _intTab.begin(); i != _intTab.end(); i++)
	{
			std::cout << *i << ", ";
	}
	std::cout << std::endl;
}
