#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <exception>
#define RED   "\033[1m\033[31m"
#define RESET "\033[0m"

int main()
{
		Form		*s_form = NULL; 
		Form		*r_form = NULL; 
		Form		*p_form = NULL; 
		Intern		intern;
		s_form = intern.makeForm("Shrubbery_Form", "TREES");
		r_form = intern.makeForm("Robotomy_Form", "Robocop");
		p_form = intern.makeForm("Presidential_Form", "Elon Musk");
	if (!s_form || !p_form || !r_form)
	{
		if (s_form)
			delete s_form;
		if (p_form)
			delete p_form;
		if (r_form)
			delete r_form;
		std::cout << "Allocation Error : Program shutdown" << std::endl;
		return 1;
	}
	try 
	{
		Bureaucrat vog("vog", 5); 

		std::cout << "\t ***********SHRUBB_TESTER************** \t"<< std::endl << std::endl;
		std::cout << vog << std::endl;
		std::cout << *s_form << std::endl;
		std::cout << *s_form << std::endl;
		
		vog.signForm(*s_form); // Sign

		std::cout << *s_form << std::endl;
		
		vog.executeForm(*s_form); // Execute

		
		std::cout << std::endl  <<"\t ***********ROBOT_TESTER************** \t"<< std::endl << std::endl;
		std::cout << *r_form << std::endl;
		std::cout << *r_form << std::endl;
		
		vog.signForm(*r_form);
		
		std::cout << *r_form << std::endl;
		
		vog.executeForm(*r_form);
		
		
		std::cout << std::endl << "\t ***********PRESIDENTIAL_TESTER************** \t"<< std::endl << std::endl;
		std::cout << *p_form << std::endl;
		std::cout << *p_form << std::endl;
	
		vog.signForm(*p_form);
		
		std::cout << *p_form << std::endl;
		
		vog.executeForm(*p_form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error : MAIN : " << e.what();
	}
		delete s_form;
		delete p_form;
		delete r_form;
	
	return (0);
}
