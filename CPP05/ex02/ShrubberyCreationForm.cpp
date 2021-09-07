#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation form", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("shrubbery creation form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	this->setSignStatus(src.getSignStatus());
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->setSignStatus(src.getSignStatus());
	_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkBeforeExecution(executor);
	std::cout << "Ici il y aura un arbre " << std::endl;
}
