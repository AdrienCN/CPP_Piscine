#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

Form*	Intern::makeForm(std::string const & form_name, std::string const & target_name)
{
	(void)form_name;
	Form* form[3] = {
		new ShrubberyCreationForm(target_name),
		new RobotomyRequestForm(target_name),
		new PresidentialPardonForm(target_name)};
	try
	{
		Form *intern_form = NULL;
		for (int i = 0; i < 3; i++)
		{
			if (form_name == form[i]->getName())
			{
				intern_form = form[i];
				for (int j = 0; j < 3; j++)
				{
					if (j != i)
						delete form[j];
				}
				std::cout << "Intern creates " << form_name << std::endl;
				return intern_form;
			}
		}
		for (int i = 0; i < 3; i++)
			delete form[i];
		throw Intern::FormNotFound();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return NULL;
}
