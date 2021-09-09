#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
T	const & max(T const & lhs, T const & rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

template<typename T>
T const & min(T const & lhs, T const & rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
void	swap(T & lhs, T & rhs)
{
	T tmp;

	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
#endif
