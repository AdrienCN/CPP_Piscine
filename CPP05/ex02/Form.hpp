#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

# ifndef BUREAU_LIMIT
# define BUREAU_LIMIT

#   define HIGH 1
#   define LOW 150

# endif


class Bureaucrat;

class Form
{
	public:
	class FormUnsignedException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "(Form) Exception caught : Form Is Not Signed\n";
				}
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "(Form) Exception caught : Grade Too High\n";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return "(Form) Exception caught : Grade Too Low\n";
				}
		};
		Form();
		Form(Form const & src);
		Form(std::string const & form_name, int const & sign_lvl, int const & exec_lvl);
		virtual ~Form();

		Form & operator=(Form const & src);

		std::string		const & getName() const;
		int const &				getSignGrade()  const;
		int const &				getExecGrade() const;
		bool const &			getSignStatus()  const;
		void	checkBeforeExecution(Bureaucrat const & executor) const;
		virtual void					execute(Bureaucrat const & executor) const = 0;
		
		void	setSignStatus(bool const & status);
		void	beSigned(Bureaucrat const & lenin);

	private:
		std::string const	_name;
		bool				_signed;
		int			const	_sign_grade;
		int			const	_exec_grade;

	protected:


};

std::ostream & operator<<(std::ostream & lhs, Form const & rhs) ;

#endif
