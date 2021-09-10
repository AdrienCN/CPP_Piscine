#include "main.hpp"
#define NS std
//std::map << overload

#include "test.cpp"

#ifndef __APPLE__


#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))
namespace stl_test
{
template<typename T>
class MutantStack : public NS::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename NS::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
}

static int main_subject(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	NS::vector<std::string> vector_str;
	NS::vector<int> vector_int;
	NS::stack<int> stack_int;
	NS::vector<Buffer> vector_buffer;
	NS::stack<Buffer, std::deque<int> > stack_deq_buffer;
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	NS::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	stl_test::MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (stl_test::MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
#endif

int main_stl()
{
	(void)test_vector;
	(void)test_stack;
	(void)test_map;
	(void)test_lexicographic;
	(void)is_integral_test;
	(void)pair_test;
	(void)make_pair_test;
	(void)swap_test;
	(void)map_order_test;
	(void)map_iter_test;
#ifndef __APPLE__
	char *argv[2];

	argv[0] = strdup("./test");
	argv[1] = strdup(ENTROPY);
	if (!argv[0] || !argv[1])
	{
		delete argv[0];
		delete argv[1];
		std::cerr << "Error: strdup failed" << std::endl;
		return 1;
	}
	(void)main_subject;
	main_subject(2, (char **)argv);
	free(argv[0]);
	free(argv[1]);
	std::cout << "Tests from subject passed" << std::endl;
#endif
	test_stack();
	std::cout << "Stack tests passed" << std::endl;
	test_vector();
	std::cout << "Vector tests passed" << std::endl;
	map_iter_test();
	map_order_test();
	test_map();
	std::cout << "Map tests passed" << std::endl;
	is_integral_test();
	std::cout << "is_integral tests passed" << std::endl;
	test_lexicographic();
	std::cout << "Lexicographic tests passed" << std::endl;
	pair_test();
	std::cout << "Pair tests passed" << std::endl;
	make_pair_test();
	std::cout << "Make_pair tests passed" << std::endl;
	swap_test();
	std::cout << "Swap tests passed" << std::endl;
	return (0);
}
