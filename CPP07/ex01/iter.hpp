#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, int size, void (*fptr)(T & target))
{
	int	i;

	i = 0;
	while (i < size)
	{
		fptr(array[i]);
		i++;
	}
}

template<typename T>
void	display(T & target)
{
	std::cout << " ["<< target << "] " << std::endl;
}
#endif
