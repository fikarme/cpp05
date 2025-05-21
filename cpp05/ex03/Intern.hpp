#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        ~Intern();
        Intern();
        Intern(const Intern &cpy);
        Intern&operator=(const Intern &cpy);
        AForm *makeForm(const string form, const string target);
        class UnknowForm : public exception {
            public:
			    virtual const char* what()const throw();
		};
};

#endif
