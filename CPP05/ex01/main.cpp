#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	Bureaucrat vog("vog", 151); // Error construction grade trop bas
	std::cout << std::endl ; // ligne vide pour la clarte d'affichage	
	
	Bureaucrat vog_2("vog_2", 0); // Error grade trop haut
	std::cout << std::endl ; // ligne vide pour la clarte d'affichage	
	
	Bureaucrat vog_default; // Construction par defautl

	
	std::cout << vog_default << std::endl; // Impression du status du bureaucrat
	vog_default.downGrade(); // Pas possible grade deja au plus bas
	vog_default.upGrade(); // Augmentation du grade
	std::cout << vog_default << std::endl; // Impression apres modif

	std::cout << std::endl ; // ligne vide pour la clarte d'affichage	
	Bureaucrat vog_first("premier_de_classe", 1); // Meme chose avec le grade le plus haut
	std::cout << vog_first << std::endl;
	vog_first.upGrade();
	vog_first.downGrade();
	std::cout << vog_first << std::endl;
	
	return (0);
}
