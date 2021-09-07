#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#define RED   "\033[1m\033[31m"
#define RESET "\033[0m"
int main()
{
	try 
	{
		//Bureaucrat vog("vog", 50); // Construction bonne
		Bureaucrat vog("vog", 151); // Error construction grade trop bas tout s'arrete;
		Form form1("F_49", 49, 49);
		Form form100("F_100", 100, 100);

		std::cout << form1 << std::endl;
		
		std::cout << std::endl;


		std::cout << form100 << std::endl;
		vog.signForm(form100); // fonctionne --> suite du code 
		vog.signForm(form1); // echoue --> catch 
	 
		//Re-impression des status des formulaires	
		std::cout << form1 << std::endl;
		
		std::cout << std::endl;


		std::cout << form100 << std::endl;

		form100.beSigned(vog); // fonctionne --> suite du code 
		std::cout << RED << "Ceci apparait" <<  RESET << std::endl;


		form1.beSigned(vog); // echoue --> catch 
		std::cout << "******PAS CELA******" << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Error : MAIN : " << e.what() << std::endl;
	}
	return (0);
}
