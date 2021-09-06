#include "Bureaucrat.hpp"
#include <stdlib.h>

Bureaucrat::Bureaucrat() : _name("nameless"),_grade(LOW)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade) : _name(name)
{
	if (this->myTry(grade))
	{
		std::cout << "Custom construction failed : Lowest grade assigned" << std::endl;
		_grade = LOW;
		return ;
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName())
{
	if (this->myTry(src._grade))
	{
		std::cout << "Copy failed : Lowest grade assigned" << std::endl;
		_grade = LOW;
		return ;
	}
	this->_grade = src.getGrade();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this->myTry(src._grade))
	{
		std::cout << "Assignation failed : Lowest grade assigned" << std::endl;
		_grade = LOW;
		return *this ;
	}
	_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}

int			const & Bureaucrat::getGrade() const
{
	return this->_grade;
}

int		Bureaucrat::myTry(int const & grade) const
{
	try
	{
		if (grade < 1)
			throw (ex_gth);
		else if (grade > 150)
			throw (ex_gtl);
	}
	catch (std::exception & e)
	{
		std::cout << "MyTry : " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

void	Bureaucrat::upGrade()
{
	try
	{
		if (this->_grade == 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	this->_grade--;
}

void	Bureaucrat::downGrade()
{
	try
	{
		if (this->_grade == 150)
			throw (ex_gtl);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	this->_grade--;
}

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return lhs;
}
