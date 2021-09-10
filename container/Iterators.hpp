#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <cstddef>

namespace ft
{
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

  template <class Iterator>
  struct iterator_traits {
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type        value_type;
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::pointer           pointer;
	typedef typename Iterator::reference         reference;
  };

  template <class T>
  struct iterator_traits<T*> {
	typedef ft::random_access_iterator_tag iterator_category;
	typedef T                          value_type;
	typedef std::ptrdiff_t       difference_type;
	typedef T*                         pointer;
	typedef T&                         reference;
  };



   //reverse_iterator reimpementation that can handle pointers
	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;

		reverse_iterator() : current() {}

		explicit reverse_iterator(iterator_type x) : current(x) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& x) : current(x.base()) {}
		iterator_type base() const
		{
			return current;
		}
		reference operator*() const
		{
			iterator_type tmp = current; return *--tmp;
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		reverse_iterator& operator++()
		{
			--current; return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this; --current; return tmp;
		}
		reverse_iterator& operator--()
		{
			++current; return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this; ++current; return tmp;
		}
		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(current - n);
		}
		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}
		reverse_iterator& operator+=(difference_type n)
		{
			current -= n; return *this;
		}
		reverse_iterator& operator-=(difference_type n)
		{
			current += n; return *this;
		}
		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
		bool operator==(const reverse_iterator& x) const
		{
			return current == x.current;
		}
		bool operator!=(const reverse_iterator& x) const
		{
			return current != x.current;
		}
		bool operator<(const reverse_iterator& x) const
		{
			return x.current < current;
		}
		bool operator>(const reverse_iterator& x) const
		{
			return x.current > current;
		}
		bool operator<=(const reverse_iterator& x) const
		{
			return x.current <= current;
		}
		bool operator>=(const reverse_iterator& x) const
		{
			return x.current >= current;
		}
	private:
		iterator_type current;
	};
}
#endif
