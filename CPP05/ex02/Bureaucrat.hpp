#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>

# ifndef BUREAU_LIMIT
# define BUREAU_LIMIT

#  define HIGH 1 
#  define LOW 150

#endif

class Form;

class Bureaucrat
{
	public:
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "(Bureau) Exception caught : Grade Too High";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "(Bureau) Exception caught : Grade Too Low";
				}
		};

		Bureaucrat();
		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat	& operator=(Bureaucrat const & src);

		std::string const & getName() const;
		int			const & getGrade() const;
		void				upGrade();
		void				downGrade();
		void				signForm(Form & form);
		void				executeForm(Form const & form);

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &  operator<<(std::ostream & lhs, Bureaucrat const & rhs);
#endif
