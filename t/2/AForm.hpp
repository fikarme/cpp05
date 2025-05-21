#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Bureaucrat;

class AForm
{
private:
	string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	AForm();
	AForm(const string &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &src);
	AForm &operator=(AForm const &src);
	~AForm();

	const string &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &b);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class FormException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif