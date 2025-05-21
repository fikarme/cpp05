#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	std::string const _name;
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
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif