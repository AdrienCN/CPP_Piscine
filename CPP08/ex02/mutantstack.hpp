#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	
	iterator begin(void)
	{
		return this->c.begin();
	}
	
	iterator end()
	{
		return this->c.begin();
	}
	private:
};
#endif
