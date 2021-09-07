#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <ctime>

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

		std::string const & getTarget() const;
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;

	protected:

};
#endif
