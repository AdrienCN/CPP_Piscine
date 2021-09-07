#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential_form", 25, 5), _target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("Presidential_form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	this->setSignStatus(src.getSignStatus());
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	this->setSignStatus(src.getSignStatus());
	_target = src._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string const & PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkBeforeExecution(executor);
	std::cout << this->_target << " has been pardoned by the President Zafod Beeblebrox" << std::endl;
}
