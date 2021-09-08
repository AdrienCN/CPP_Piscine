#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cfloat>
#include <climits>

enum e_dataType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NA
};

class Convert
{
	public:
		Convert();
		Convert(Convert const & src);
		Convert(std::string const & str);
	Convert	&  operator=(Convert const & src);
		~Convert();

		e_dataType	const & getType() const;
		std::string const &	getData() const;

		void		id_data(void);
		void		printChar(char const & c) const;

		void		convert_data(void);
		void		isInt() const;
		void		isChar() const;
		void		isFloat() const;
		void		isDouble() const;

	private:
	e_dataType 		_dataType;
	std::string		_data;
};
#endif
