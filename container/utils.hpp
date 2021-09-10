#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	//swap reimpementation
	template<typename T>
	void swap(T& lhs, T& rhs)
	{
		T temp(lhs);
		lhs = rhs;
		rhs = temp;
	}

}

#endif
