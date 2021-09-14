#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;

	// Adding seven(7) elements to stack 
	std::cout << "Pushing seven(7) new elements ..." << std::endl;
	mstack.push(21);
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(42);

	//Showing stack status 
	std::cout << "Element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl << std::endl;

	// Remove one element from stack
	std::cout << "Popping one element ..." << std::endl;
	mstack.pop(); 
	std::cout << "New element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl << std::endl;

	// Adding four(4) elements to stack 
	std::cout << "Pushing four(4) new elements ..." << std::endl;
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(42);

	//Showing stack status 
	std::cout << "New element in TOP: " << mstack.top() << std::endl;
	std::cout << "Stack SIZE: " << mstack.size() << std::endl << std::endl;


	//Iterate through stack + display each elements 
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "stack start is [it] =  " << *it << std::endl;
	++it;
	std::cout << "++it =  " << *it << std::endl;
	--it;
	std::cout << "--it = " << *it << std::endl;
	std::cout << "stack content: " << std::endl;
	int i = 0;
	while (it != ite)
	{	
		std::cout << "[it + " << i << "] = " << *it << std::endl;
		++it;
		++i;
	}
	std::stack<int> s(mstack);
	return 0;
}
