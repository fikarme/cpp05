#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy) {
    *this = cpy;
}

Intern &Intern::operator = (const Intern &cpy) {
    (void)cpy;
    return (*this);
}

AForm *Intern::makeForm(const std::string form, const std::string target) {
    int i = -1;
	AForm *iter = NULL;
    std::string form_types[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    while (++i < 3)
        if (form == form_types[i])
            break;
	switch (i)
	{
		case 0:
			iter = new ShrubberyCreationForm(target);
			break;
		case 1:
			iter = new RobotomyRequestForm(target);
			break;
		case 2:
			iter = new PresidentialPardonForm(target);
			break;
		default:
			throw (Intern::UnknowForm());
	}
    return (iter);
}

const char* Intern::UnknowForm:: what() const throw() {
	return ("Unknown form name.");
}

Intern::~Intern() {}