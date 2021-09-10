#ifndef SPAN_HPP
#define SPAN_HPP

template <typename T>
class Span
{

	public :
		T(unsigned int N);
		T(T const & src);
		T & operator=(T const & src);

		~T();
		
		void	addNumber(int newNb);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		unsigned int	getSize() const;

		class Empty_Or_Single : public std::exception
		{
			public:
				virtual  const char* what(void) const throw()
				{
					return "Exception : Span : Container is EMPTY or has ONE data only";
				}
		};

		class Already_Full : public std::exception
		{
		public:
			virtual const char * what(void) const throw()
			{
				return "Exception : Span : Container is already FULL";
			}
		};
	


	private:
		T();
		unsigned int _size;
		int			*_data;
};

#endif
