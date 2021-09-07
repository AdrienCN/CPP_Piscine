#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"),_grade(LOW)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade) : _name(name)
{	
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName())
{	
	if (src._grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (src._grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = src.getGrade();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	if (src._grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (src._grade > 150)
		throw (Bureaucrat::GradeTooLowException());
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

void	Bureaucrat::upGrade()
{
	try
	{
		if (this->_grade == 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (std::exception &e)
	{
		std::cout << "Error : BUREAUCRAT : Upgrade : ";
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
		std::cout << "Error : BUREAUCRAT : Downgrade : ";
		std::cout << e.what() << std::endl;
		return ;
	}
	this->_grade++;
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception & e)
	{
		std::cout << this->_name << " CANNOT sign " << form.getName() << " because : ";
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << this->_name << " signs " << form.getName() << std::endl;
}


std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return lhs;
}
