#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &cpy);
        Intern& operator = (const Intern &cpy);
        AForm *makeForm(const std::string form, const std::string target);
        class UnknowForm : public std::exception {
			virtual const char* what()const throw();
		};
        ~Intern();
};

#endif