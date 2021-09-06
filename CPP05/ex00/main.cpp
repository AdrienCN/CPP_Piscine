#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	Bureaucrat vog("vog", 0);
	std::cout << vog.getGrade() << std::endl;
	vog.downGrade();
	std::cout << vog.getGrade() << std::endl;
	std::cout << vog <<  std::endl;
	return (0);
}
