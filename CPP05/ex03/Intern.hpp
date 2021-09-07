#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class FormNotFound : public	std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "Error : (Intern) Exception caught : Form Not Found\n";
				}
		};
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const & src);
	
		Form*	makeForm(std::string const & form_name, std::string const & target_name);
	
	private:


	protected:
	
};
#endif
