#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(21);
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(42);

	std::cout << "Element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl;
	std::cout << "Popping one element ..." << std::endl;
	mstack.pop();
	std::cout << "New element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl;
	std::cout << "Pushing element ..." << std::endl;
	std::cout << "Pushing element ..." << std::endl;
	std::cout << "Pushing element ..." << std::endl;
	std::cout << "Pushing element ..." << std::endl;
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(42);
	std::cout << "New element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "it: " << *it << std::endl;
	++it;
	std::cout << "++it: " << *it << std::endl;
	--it;
	std::cout << "--it: " << *it << std::endl;
	std::cout << "stack content: " << std::endl;
	while (it != ite)
	{	
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
