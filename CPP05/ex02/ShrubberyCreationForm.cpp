#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation form", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string & const target) : Form("shrubbery creation form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	this->setSignStatus(src.getSignStatus());
}

ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src)
{
	this->setSignStatus(src.getSignStatus());
	_target = src._target;
	return *this;
}

std::string const & getTarget() const
{
	return this->_target;
}

void	execute(Bureaucrat const & executor) const
{
	this->CheckExecution(executor);
	std::cout << "Ici il y aura un arbre " << std::endl;
}
