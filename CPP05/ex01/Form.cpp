#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("nameless_form"), _sign_grade(HIGH), _exec_grade(HIGH), _signed(false)
{
}

Form::Form(std::string const & form_name, int const & sign_lvl, int const & exec_lvl) : _name(form_name), _sign_grade(sign_lvl), _exec_grade(HIGH), _signed(false)
{
	// implementer le try / catch;
}

Form::Form(Form const & src): _name(src._name), _sign_lvl(src.getSignGrade()), _exec_grade(src.getExecGrade()), _signed(src.getSignStatus())
{
	// try / catch ????
}

Form & Form::operator=(Form const & src)
{
	_name = src.getName();
	_sign_grade = src.getSignGrade();
	_exec_grade = src.getExecGrade();
	_signed = src.getSignStatus();
	return *this;
}

Form::~Form()
{

}

std::string const & Form::getName() const
{
	return this->_name;
}

int const & Form::getSignGrade()  const
{
	this->_sign_grade;
}

int const & Form::getExecGrade() const
{
	this->_sign_exec;
}

bool const & Form::getSignStatus()  const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat const & lenin);
{
	try
	{
		if (lenin.getGrade() > this->_sign_grade)
			throw (Form::GradeTooLowException());
	}
	catch (std::exception &e)
	{
		std::cout << "Error : Cannot sign FORM : " << e.what() << std::cout;
		return ;
	}
	this->_signed = true;
}

std::ostream & operator<<(std::ostream & lhs, Bureaucrat const & rhs)
{
	lhs << "Form name : " << rhs.getName() <<  std::endl;
	if (rhs.getSignStatus() == true)
		lhs << "Signed_status : Signed" << std::endl;
	else
		lhs << "Signed_status : Unsigned" << std::endl;

	lhs << "Grade_to_sign : " << rhs.getSignGrade << std::endl;
	lhs << "Grade_to_exec : " << rhs.getExecGrade() << std::endl;
	return lhs;
}
