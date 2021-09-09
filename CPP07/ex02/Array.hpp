#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class  Array
{
	public:
		class OutOfRange : public  std::exception
	{
		public :
			virtual const char * what(void) const throw()
			{
				return "Error : Index is out of range" ;
			}
	};
		Array() : _array(NULL) , _size(0) {};
		
		Array(unsigned int n) : _array(new T[n]()), _size(n){};
		
		Array(Array const & src) : _array(new T[src.getSize()]()), _size(src.getSize())
		{
			unsigned int i;

			for (i = 0; i < _size; i++)
				_array[i] = src._array[i];
		};

		Array & operator=(Array const & src)
		{
			if (_size > 0)
				delete  [] _array;
			_size = src.getSize();
			_array = new T[src.getSize()]();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
			return *this;
		}

		~Array() 
		{
			if (_size > 0)
				delete [] _array;
		};

		T & operator[](unsigned int index) const
		{
			if (index < 0 || index >= _size)
				throw Array::OutOfRange();
			else
				return (_array[index]);
		}
		unsigned int getSize(void) const
		{
			return _size;
		}
	
	private:
		T*	_array;
		unsigned int _size;
};
#endif
