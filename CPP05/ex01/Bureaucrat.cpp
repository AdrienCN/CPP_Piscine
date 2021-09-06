#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"),_grade(LOW)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade) : _name(name)
{
	if (this->myTry(grade))
	{
		std::cout << "Custom constructor : Error grade value : Lowest grade assigned" << std::endl;
		_grade = LOW;
		return ;
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName())
{
	if (this->myTry(src._grade))
	{
		std::cout << "Copy Constructor : Error grade value : Lowest grade assigned" << std::endl;
		_grade = LOW;
		return ;
	}
	this->_grade = src.getGrade();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
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
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
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
			throw (Bureaucrat::GradeTooLowException());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	this->_grade++;
}

void	Bureaucrat::signForm(Form const & form)
{
	if (this->_grade < form.getSignGrade())
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	else
		std::cout << this->_name << "cannot signs " << form.getName() << " because grade is too low" << std::endl;


std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return lhs;
}
