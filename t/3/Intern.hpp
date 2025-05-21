#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:
	Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern();
	AForm *makeForm(std::string name, std::string target);
	class FormException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif