#include "Convert.hpp"

Convert::Convert() : _dataType(NA), _data("NULL")
{
	this->id_data();	
}

Convert::Convert(Convert const & src) : _dataType(src.getType()), _data(src.getData())
{
	this->id_data();	
}

Convert::Convert(std::string const & str) : _dataType(NA), _data(str)
{
	this->id_data();	
}

Convert & Convert::operator=(Convert const & src)
{
	_data = src.getData();
	_dataType = src.getType();
	return *this;
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

	// Id INT
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
	switch (this->_dataType)
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

void	Convert::printChar(char const & c) const
{
	std::cout << "char : ";
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "is not printable" << std::endl;
}

void	Convert::isChar(void) const
{
	char c = _data[0];
	if (c < SCHAR_MIN || c > SCHAR_MAX)
		std::cerr << "Error : Input : [CHAR] is out of range. Conversion aborted" << std::endl;
	this->printChar(c);
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void	Convert::isInt(void) const
{
	try 
	{
		int i = std::stoi(_data, NULL);
		
		//Display CHAR
		if (i < static_cast<int>(SCHAR_MIN)  || i > static_cast<int>(SCHAR_MAX))
			std::cout << "char : overflow or underflow" << std::endl;
		else
			this->printChar(static_cast<char>(i));
		
		std::cout << "int : " << i << std::endl;
		std::cout << "float : " << static_cast<float>(i) << std::endl;
		std::cout << "double : " << static_cast<double>(i) << std::endl;
	}
	catch (const std::out_of_range & oor)
	{
		std::cerr << "Error : Input : [INT] is out of range. Conversion aborted" << std::endl;
	}
}

void	Convert::isFloat(void) const
{
	try
	{
		//cas -inff +inff nanf
		float f = std::stof(_data, NULL);
		//Display CHAR
		if (f < static_cast<float>(CHAR_MIN) || f > static_cast<float>(CHAR_MAX))
			std::cout << "char : overflow or underflow" << std::endl;
		else
			this->printChar(static_cast<char>(f));
		// Display INT
		if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
			std::cout << "int : overflow or underflow" << std::endl;
		else	
			std::cout << "int : " << static_cast<int>(f) << std::endl;
		//Display FLOAT
		std::cout << "float : " << f << std::endl;

		//Display DOUBLE
		std::cout << "double : " << static_cast<double>(f) << std::endl;
	}
	catch (const std::out_of_range & oor)
	{
		std::cerr << "Error : Input : [FLOAT] is out of range. Conversion aborted" << std::endl;
	}
	
}

void	Convert::isDouble(void) const
{
	//cas -inf +inf nan
	try
	{
		double d = std::stod(_data, NULL);
		//Display CHAR
		if (d < static_cast<double>(CHAR_MIN) || d > static_cast<float>(CHAR_MAX))
			std::cout << "char : overflow or underflow" << std::endl;
		else
			this->printChar(static_cast<char>(d));
		// Display INT
		if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
			std::cout << "int : overflow or underflow" << std::endl;
		else	
			std::cout << "int : " << static_cast<int>(d) << std::endl;
		//Display FLOAT
		
		if (_data == "nan" || _data == "inf" || _data == "+inf" || _data == "-inf")
			std::cout << "float : " << static_cast<float>(d) << std::endl;
		else if (d > static_cast<double>(FLT_MAX) || d < static_cast<double>(-FLT_MAX)) 
			std::cout << "float : overflow or underflow" << std::endl;
		else
			std::cout << "float : " << static_cast<float>(d) << std::endl;

		//Display DOUBLE
		std::cout << "double : " << d << std::endl;
	}
	catch (const std::out_of_range & oor)
	{
		std::cerr << "Error : Input : [DOUBLE] is out of range. Conversion aborted" << std::endl;
	}
}

e_dataType	const & Convert::getType(void) const
{
	return this->_dataType;
}

std::string const & Convert::getData(void) const
{
	return this->_data;
}
