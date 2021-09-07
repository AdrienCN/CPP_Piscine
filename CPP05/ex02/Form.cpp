#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("nameless_form"), _signed(false), _sign_grade(HIGH), _exec_grade(HIGH)
{
}

Form::Form(std::string const & form_name, int const & sign_lvl, int const & exec_lvl) : _name(form_name), _signed(false) , _sign_grade(sign_lvl), _exec_grade(exec_lvl)
{
	if (_exec_grade > 150 || _sign_grade > 150)
		throw (Form::GradeTooLowException());
	else if (_exec_grade < 1 || _sign_grade < 1)
		throw (Form::GradeTooHighException());
	return;
}

Form::Form(Form const & src): _name(src._name), _signed(src.getSignStatus())
, _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()){

		if (_exec_grade > 150 || _sign_grade > 150)
		throw (Form::GradeTooLowException());
	else if (_exec_grade < 1 || _sign_grade < 1)
		throw (Form::GradeTooHighException());
	return;
}

Form & Form::operator=(Form const & src)
{
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
	return this->_sign_grade;
}

int const & Form::getExecGrade() const
{
	 return this->_exec_grade;
}

bool const & Form::getSignStatus()  const
{
	return this->_signed;
}
void	Form::checkBeforeExecution(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw Form::FormUnsignedException();
	if (this->_exec_grade < executor.getGrade())
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat const & lenin)
{
	if (lenin.getGrade() > this->_sign_grade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

void		Form::setSignStatus(bool const & status)
{
	this->_signed = status;
}

std::ostream & operator<<(std::ostream & lhs, Form const & rhs)
{
	lhs << "Form name : " << rhs.getName() <<  std::endl;
	if (rhs.getSignStatus() == true)
		lhs << "Signed_status : Signed" << std::endl;
	else
		lhs << "Signed_status : Unsigned" << std::endl;

	lhs << "Grade_to_sign : " << rhs.getSignGrade() << std::endl;
	lhs << "Grade_to_exec : " << rhs.getExecGrade() << std::endl;
	return lhs;
}


