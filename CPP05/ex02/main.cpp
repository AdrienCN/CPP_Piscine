#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#define RED   "\033[1m\033[31m"
#define RESET "\033[0m"

int main()
{
		Form		*s_form_100 = new ShrubberyCreationForm("TARGET_100");
		Form		*s_form_50 = new ShrubberyCreationForm("TARGET_50");
	try 
	{
		Bureaucrat vog_50("vog_50", 138);

		std::cout << vog_50 << std::endl;
		std::cout << *s_form_50 << std::endl;
		std::cout << *s_form_100 << std::endl;

		vog_50.signForm(*s_form_50);
		std::cout << *s_form_50 << std::endl;

		vog_50.upGrade();
		s_form_50->execute(vog_50);
		
		
	}
	catch (std::exception &e)
	{
		std::cout << "Error : MAIN : " << e.what();
	}
		delete s_form_100;
		delete s_form_50;
	
	return (0);
}
