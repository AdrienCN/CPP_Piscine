#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery_Form", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("Shrubbery_Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	this->setSignStatus(src.getSignStatus());
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->setSignStatus(src.getSignStatus());
	_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream tree_file;
	std::string	  filename;

	this->checkBeforeExecution(executor);
	filename = this->_target + "_shrubbery";
	tree_file.open(filename.c_str() , std::ios::out | std::ios::trunc);
	if (tree_file.is_open())
	{
		tree_file << "\033[1m\033[32m" << "         .     .  .      +     .      .          .\n"
						   "     .       .      .     #       .           .\n"
						   "        .      .         ###            .      .      .\n"
						   "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
						   "          .      . \"####\"###\"####\"  .\n"
						   "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
						   "  .             \"#########\"#########\"        .        .\n"
						   "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
						   "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
						   "                .\"##\"#####\"#####\"##\"           .      .\n"
						   "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
						   "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
						   "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
						   "            .     \"      000      \"    .     .\n"
						   "       .         .   .   000     .        .       .\n"
						   ".. .. ..................O000O........................ ...... ..." << "\033[0m\033[0m" << std::endl;

	}
	else
		throw Form::ErrorOpeningFile();
	tree_file.close();
}
