#ifndef STACK_HPP
# define STACK_HPP
#include "Vector.hpp"
#include <list>
#include <deque>
#include <vector>
namespace ft
{
		//stack custom container declaration
	template<typename T, typename C = std::deque<T> >
	class stack
	{
		protected:
			C c;
		public:
			typedef C container_type;
			typedef typename C::value_type value_type;
			typedef typename C::size_type size_type;
			typedef typename C::reference reference;
			typedef typename C::const_reference const_reference;

			//constructors
			explicit stack( const C& cont = C() )
				: c(cont)
			{
			}
			//destructors
			~stack()
			{}
			//assign
			stack& operator=(const stack& rhs)
			{
				c = rhs.c;
				return *this;
			}
			//push
			void push(const value_type& value)
			{
				c.push_back(value);
			}
			//pop
			void pop()
			{
				c.pop_back();
			}
			//top
			reference top()
			{
				return c.back();
			}
			const_reference top() const
			{
				return c.back();
			}
			//size
			size_type size() const
			{
				return c.size();
			}
			//empty
			bool empty() const
			{
				return c.empty();
			}
/*
Non-member functions
operator==
operator!=
operator<
operator<=
operator>
operator>= 
lexicographically compares the values in the stack
(function template)
*/
	friend bool operator==(const stack& lhs, const stack& rhs)
	{
		return lhs.c == rhs.c;
	}
	friend bool operator!=(const stack& lhs, const stack& rhs)
	{
		return lhs.c != rhs.c;
	}
	friend bool operator<(const stack& lhs, const stack& rhs)
	{
		return lhs.c < rhs.c;
	}
	friend bool operator<=(const stack& lhs, const stack& rhs)
	{
		return lhs.c <= rhs.c;
	}
	friend bool operator>(const stack& lhs, const stack& rhs)
	{
		return lhs.c > rhs.c;
	}
	friend bool operator>=(const stack& lhs, const stack& rhs)
	{
		return lhs.c >= rhs.c;
	}
};
}

#endif
