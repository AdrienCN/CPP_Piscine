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
			this->_data.erase(1, 1); // ---> pk ?
		this->_dataType = FLOAT;
		return;
	}
	if (input == "inf" || input == " inf" || input == "nan")
	{
		if (input == " inf")
			this->_data.erase(1, 1); // ---> pk ?
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
			isNa();
	}
}
