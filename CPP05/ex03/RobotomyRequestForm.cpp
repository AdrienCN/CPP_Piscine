#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy_Form", 72, 45), _target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("Robotomy_Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	this->setSignStatus(src.getSignStatus());
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	this->setSignStatus(src.getSignStatus());
	_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string const & RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkBeforeExecution(executor);
	srand(time(NULL));
	std::cout << "bbrrrrrBRrr....(drilling noise)..." << std::endl;
	if (rand() % 2)
		std::cout << "...wooooops .. " << this->_target << " robotomy has failed" << std::endl;
	else
		std::cout << this->_target << " has successfully been robotomised"<< std::endl;
}
