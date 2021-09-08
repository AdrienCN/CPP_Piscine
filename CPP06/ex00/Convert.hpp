#ifndef CONVERT_HPP
#define CONVERT_HPP

enum e_dataType
{
	CHAR = 0;
	INT;
	FLOAT;
	DOUBLE;
	NA;
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

		void		id_data(std::string const & src);
		void		convert_data(void);
		void		isInt();
		void		isChar();
		void		isFloat();
		void		isDouble();
		void		isNa();

	private:
	e_dataType 		_dataType;
	std::string		_data;
};
#endif
