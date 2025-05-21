#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::exception;

class Form;

class Bureaucrat {
	private:
		const string	_name;
		int				_grade;
	public:
		~Bureaucrat();
		Bureaucrat(const string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &oper);
		
		string	getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();

        void    signForm(Form &f);

		class GradeTooHighException : public exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public exception {
			public:
				virtual const char* what() const throw();
		};
};

ostream &operator << (ostream &output, const Bureaucrat &b);

#endif