#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::exception;

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

		class GradeTooHighException : public exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif