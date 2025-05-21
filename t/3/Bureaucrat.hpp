#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class AForm;

class Bureaucrat
{
private:
	string const _name;
	int _grade;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

public:
	Bureaucrat();
	Bureaucrat(const string &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	~Bureaucrat();

	const string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);

	void executeForm(AForm const &form) const;
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif