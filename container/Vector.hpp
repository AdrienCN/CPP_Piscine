#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "utils.hpp"
# include "Iterators.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <cassert>
#include <limits>
#include <cstddef>
#define GROWTH_RATE 2
namespace ft
{
    	//vector class definition with allocator
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:

			typedef typename iterator_traits<T*>::iterator_category iterator_category;
			typedef typename iterator_traits<T*>::value_type        value_type;
			typedef typename iterator_traits<T*>::difference_type   difference_type;
			typedef typename iterator_traits<T*>::pointer           pointer;
			typedef typename iterator_traits<T*>::reference         reference;
			//allocator type
			typedef Alloc                                           allocator_type;

			//membertypes
			typedef typename allocator_type::const_pointer 			const_pointer;
			typedef pointer iterator;
			typedef pointer const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			//size_type
			typedef size_t size_type;
			//reference
			typedef const T& const_reference;
			//container type
			typedef vector<T> container_type;

			
		private:         
			pointer data;
			size_type _size;
			size_type _capacity;
			allocator_type alloc;
			//allocator using std::allocator
			//allocator type
		public:
			//constructors
			vector(const vector<value_type>& v)
			{
				_size = v._size;
				_capacity = v._capacity;
				data = alloc.allocate(_capacity);
				std::uninitialized_copy(v.begin(), v.end(), data);
			}
			explicit vector( const allocator_type& new_alloc = std::allocator<value_type>() )
			{
				alloc = new_alloc;
				data = alloc.allocate(0);
				_size = 0;
				_capacity = 0;
			}
			explicit vector( size_type count, const T& value = T(), const allocator_type& new_alloc = std::allocator<allocator_type>())
			{
				alloc = new_alloc;
				data = alloc.allocate(count);
				_size = count;
				_capacity = count;
				for (size_type i = 0; i < _size; i++)
					data[i] = value;
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& new_alloc = std::allocator<allocator_type>())
			{
				alloc = new_alloc;
				_size = 0;
				_capacity = 0;
				for (; first != last; ++first)
					push_back(*first);
			}



			~vector()
			{
				alloc.deallocate(data, _capacity);
			}
			reference operator[](size_type i)
			{
				if (i >= _size)
					throw std::out_of_range("vector<value_type>::operator[]: index out of range");
				return data[i];
			}
			const_reference operator[](size_type i) const
			{
				if (i >= _size)
					throw std::out_of_range("vector<value_type>::operator[]: index out of range");
				return data[i];
			}
			size_type size() const
			{
				return _size;
			}
			size_type capacity() const
			{
				return _capacity;
			}
			void push_back(const_reference x)
			{
				if (_size == _capacity)
				{
					if (_capacity == 0)
						_capacity = sizeof(value_type);
					reserve(_capacity * GROWTH_RATE);
				}
				alloc.construct(data + _size, x);
				++_size;
			}
			void pop_back()
			{
				if (_size == 0)
					throw std::out_of_range("vector<value_type>::pop_back(): empty vector");
				_size--;
			}			
			reference back()
			{
				if (_size == 0)
					throw std::out_of_range("vector<value_type>::back(): empty vector");
				return data[_size-1];
			}
			const_reference back() const
			{
				if (_size == 0)
					throw std::out_of_range("vector<value_type>::back(): empty vector");
				return data[_size-1];
			}
			reference front()
			{
				if (_size == 0)
					throw std::out_of_range("vector<value_type>::front(): empty vector");
				return data[0];
			}
			const_reference front() const
			{
				if (_size == 0)
					throw std::out_of_range("vector<value_type>::front(): empty vector");
				return data[0];
			}
			void clear()
			{
				_size = 0;
			}
			void resize(size_type n)
			{
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = n;
				}
				_size = n;
			}
			//empty
			bool empty() const
			{
				return _size == 0;
			}
			//max_size
			size_type max_size() const
			{
				return std::numeric_limits<size_type>::max();
			}
			//reserve
			void reserve(size_type n)
			{
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					std::uninitialized_copy(data, data + _size, temp);
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = n;
				}
			}
			//assign
			void assign(size_type n, const_reference val)
			{
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = n;
				}
				_size = n;
				for (size_type i = 0; i < _size; i++)
					data[i] = val;
			}

			template< class InputIt >
			void assign(typename ft::enable_if<!std::numeric_limits<InputIt>::is_integer, InputIt>::type first, InputIt last )
			{
				size_type n = last - first;
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = n;
				}
				_size = n;
				for (size_type i = 0; i < _size; i++)
					data[i] = *(first++);
			}

			//insert
			void insert(size_type pos, const_reference x)
			{
				if (pos > _size)
					throw std::out_of_range("vector<value_type>::insert(): index out of range");
				if (_size == _capacity)
				{
					_capacity = (_capacity + 1) * 2;
					pointer temp = alloc.allocate(_capacity);
					for (size_type i = 0; i < pos; i++)
						temp[i] = data[i];
					temp[pos] = x;
					for (size_type i = pos; i < _size; i++)
						temp[i+1] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
				}
				else
				{
					for (size_type i = _size; i > pos; i--)
						data[i] = data[i-1];
					data[pos] = x;
				}
				_size++;
			}
			//erase
			void erase(size_type pos)
			{
				if (pos >= _size)
					throw std::out_of_range("vector<value_type>::erase(): index out of range");
				for (size_type i = pos; i < _size-1; i++)
					data[i] = data[i+1];
				_size--;
			}
			//erase
			void erase(size_type pos, size_type n)
			{
				if (pos >= _size)
					throw std::out_of_range("vector<value_type>::erase(): index out of range");
				if (pos+n > _size)
					throw std::out_of_range("vector<value_type>::erase(): index out of range");
				for (size_type i = pos; i < _size-n; i++)
					data[i] = data[i+n];
				_size -= n;
			}
			//resize
			void resize(size_type n, const_reference val)
			{
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = n;
				}
				_size = n;
				for (size_type i = _size; i < _capacity; i++)
					data[i] = val;
			}
			//operator=
			vector<value_type>& operator=(const vector<value_type>& v)
			{
				if (this == &v)
					return *this;
				if (_capacity < v._size)
				{
					pointer temp = alloc.allocate(v._size);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = v._size;
				}
				_size = v._size;
				for (size_type i = 0; i < _size; i++)
					data[i] = v.data[i];
				return *this;
			}
			//operator==
			friend bool operator==(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				if (v1._size != v2._size)
					return false;
				return ft::equal(v1.data, v1.data+v1._size, v2.data, v2.data+v2._size);
			}
			//operator!=
			friend bool operator!=(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				return !(v1 == v2);
			}
			
			/*//operator<<
			friend std::ostream& operator<<(std::ostream& os, const vector<value_type>& v)
			{
				os << "[";
				for (size_type i = 0; i < v._size; i++)
				{
					os << v.data[i];
					if (i != v._size-1)
						os << ", ";
				}
				os << "]";
				return os;
			}

			//operator>>
			friend std::istream& operator>>(std::istream& is, vector<value_type>& v)
			{
				is >> v.data;
				return is;
			}
*/			
			friend bool operator<(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				if (v1._size < v2._size)
					return true;
				else if (v1._size > v2._size)
					return false;
				else
					return ft::lexicographical_compare(v1.data, v1.data+v1._size, v2.data, v2.data+v2._size);
			}
			friend bool operator>(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				return v2 < v1;
			}
			friend bool operator<=(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				return !(v2 < v1);
			}
			friend bool operator>=(const vector<value_type>& v1, const vector<value_type>& v2)
			{
				return !(v1 < v2);
			}


			iterator begin()
			{
				return iterator(data);  
			}
			iterator end()
			{
				return iterator(data+_size);
			}
			const_iterator begin() const
			{
				return const_iterator(data);
			}
			const_iterator end() const
			{
				return const_iterator(data+_size);
			}

			//insert with iterator
			iterator insert(iterator pos, const_reference value)
			{
				if (pos == end() || pos == end()-1)
				{
					push_back(value);
					return end()-1;
				}
				if (_size+1 > _capacity)
				{
					pointer temp = alloc.allocate(_size+1);
					for (size_type i = 0; i < _size; i++)
						temp[i] = data[i];
					alloc.deallocate(data, _capacity);
					data = temp;
					_capacity = _size+1;
				}
				for (size_type i = _size; i > (size_type)(pos-data); i--)
					data[i] = data[i-1];
				data[pos-data] = value;
				_size++;
				return pos;
			}
			//erase with iterator
			iterator erase(iterator pos)
			{
				for (size_type i = pos-data; i < _size-1; i++)
					data[i] = data[i+1];
				_size--;
				return pos;
			}
			//erase with range
			iterator erase(iterator first, iterator last)
			{
				for (size_type i = first-data; i < last-data; i++)
					data[i] = data[i+1];
				_size -= last-first;
				return first;
			}
			//at 
			reference at(size_type pos)
			{
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return data[pos];
			}
			const_reference at(size_type pos) const
			{
				if (pos >= _size)
					throw std::out_of_range("vector::at");
				return data[pos];
			}
		//get_allocator
		allocator_type get_allocator() const
		{
			return alloc;
		}
		//reverse_iterator
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		//swap
		void swap(vector<value_type>& v)
		{
			ft::swap(data, v.data);
			ft::swap(_size, v._size);
			ft::swap(_capacity, v._capacity);
		}
		//swap two vectors
		friend void swap(vector<value_type>& v1, vector<value_type>& v2)
		{
			v1.swap(v2);
		}
	};
}

#endif
