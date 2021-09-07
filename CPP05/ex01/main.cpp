#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#define RED   "\033[1m\033[31m"
#define RESET "\033[0m"

int main()
{
	try 
	{
		Bureaucrat vog("\033[1m\033[32mVog_lvl_50\033[0m", 50); // Construction bonne
		
		//A decommenter pour l'exemple : grade trop bas tout s'arrete;
		//Bureaucrat vog("vog", 150);	
		
		Form form1("F_49", 49, 49);
		Form form100("F_100", 100, 100);

		std::cout << form1 << std::endl;
		
		std::cout << std::endl;


		std::cout << form100 << std::endl;
		vog.signForm(form100); // Gestion d'erreur interne 
		vog.signForm(form1); // Gestion d'erreur interne
		std::cout << RED << "Suite du code : Erreur gerer en interne. Status des formulaires change" <<  RESET << std::endl;
		//Re-impression des status des formulaires	
		std::cout << form1 << std::endl;
		
		std::cout << std::endl;


		std::cout << form100 << std::endl;

		form100.beSigned(vog); // fonctionne --> suite du code 
		std::cout << RED << "Ceci apparait mais pas le suivant" <<  RESET << std::endl;


		form1.beSigned(vog); // echoue --> catch 
		std::cout << "******PAS CELA******" << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Error : MAIN : " << e.what();
	}
	return (0);
}
