#include "Convert.hpp"

Convert::Convert() : _data("NULL"), _dataType(NA)
{
}

Convert::Convert(Convert const & src) : _data(src.getData()), dataType(src.getType())
{
}

Convert::Convert(std::string const & str) : _data(str), _dataType(NA)
{
	this->id_data(str);	
}

Convert & Convert::operator=(Convert const & src)
{
	_data = src.getData();
	_datatype() = src.getType();
}

Convert::~Convert()
{
}

void	Convert::id_data(void)
{
	std::string input = _data;

	// id CHAR
	if (input.length() == 1 && std::isdigit(input[0]) == 0 && std::isprint(input[0]))
	{
		this->_dataType = CHAR;
		return;
	}

	// Id FLOAT
	if (input[0] == '+' || input[0] == '-')
		input.erase(0, 1);
	if (input == "inff" || input == " inff" || input == "nanf")
	{
		if (input == " inff")
			this->_data.erase(1, 1); // suppresion de l'espace car sujet typo
		this->_dataType = FLOAT;
		return;
	}
	if (input == "inf" || input == " inf" || input == "nan")
	{
		if (input == " inf")
			this->_data.erase(1, 1);
		this->_dataType = DOUBLE;
		return;
	}
	size_t pos;
	pos = input.find_first_not_of("0123456789"); // cherche un '.' ou un 'f'
	if (pos == input.npos)
	{
		this->_dataType = INT;
		return;
	}
	else if (pos == 0 || input[pos] != '.' || pos + 1 == input.length())
		return; //NA
	std::string substr = input.substr(pos + 1);
	pos = substr.find_first_not_of("0123456789");
	if (pos == substr.npos)
	{
		this->_dataType = DOUBLE;
		return;
	}
	else if (pos != 0 && substr[pos] == 'f' && pos + 1 == substr.length())
	{
		this->_dataType = FLOAT;
		return;
	}
	return; //NA
}

void	Convert::convert_data(void)
{
	switch (this->_dataType())
	{
		case 0:
			isChar();
			break;
		case 1:
			isInt();
			break;
		case 2:
			isFloat();
			break;
		case 3:
			isDouble();
			break;
		default:
			std::cout << "Error : Conversion Non Applicable" << std::endl;
	}
}

void	Convert::printChar(char const & c)
{
	std::cout << "char : " << c << std::endl;
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	Convert::isChar(void) const;
{
	char c = _data[0];
	this->printChar(c);
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void	Convert::isInt(void) const;
{
	long int i = std::stol(_data, NULL, 10);
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char : overflow or underflow" << std::endl;
	else
		this->printChar(static_cast<char>(i));
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int : overflow or underflow" << std::endl;
	else	
		std::cout << "int : " << i << std::endl;
	std::cout << "float : " << static_cast<float>(i) << std::endl;
	std::cout << "double : " << static_cast<double>(i) << std::endl;

}

void	Convert::isFloat(void) const;
{
	//cas -inff +inff nanf
	float f = std::stof(_data, NULL, 10);
}

void	Convert::isDouble(void) const;
{
	//cas -inf +inf nan
	double d = std::stod(_data, NULL, 10);
}

