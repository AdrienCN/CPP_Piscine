#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#define RED   "\033[1m\033[31m"
#define RESET "\033[0m"

int main()
{
		Form		*s_form = new ShrubberyCreationForm("TREEFILE_TARGET");
		Form		*r_form = new RobotomyRequestForm("Robotomy_TARGET");
		Form		*p_form = new PresidentialPardonForm("President_TARGET");

	try 
	{
		// Val a test apres "vog" : 145 - 137 | 72 - 45 | 25 - 5
		// 137 Shrubb ok : rest non
		// 45 Shurbb + Robot
		// 5 Tout
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
