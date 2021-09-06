#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>


#define HIGH 1 
#define LOW 150
class Bureaucrat
{
	public:
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "Exception caught : Grade Too High";
				}
		} ex_gth;
		
		class GradeTooLow : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "Exception caught : Grade Too Low";
				}
		} ex_gtl;

		Bureaucrat();
		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat	& operator=(Bureaucrat const & src);

		std::string const & getName() const;
		int			const & getGrade() const;
		int					myTry(int const & grade) const;
		void				upGrade();
		void				downGrade();

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &  operator<<(std::ostream & lhs, Bureaucrat const & rhs);
#endif
