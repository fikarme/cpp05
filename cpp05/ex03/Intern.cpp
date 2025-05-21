#include "Intern.hpp"

Intern::~Intern() {}

Intern::Intern() {}

Intern::Intern(const Intern &cpy) {
    *this = cpy;
}

Intern &Intern::operator=(const Intern &cpy) {
    (void)cpy;
    return (*this);
}

AForm *Intern::makeForm(const string form, const string target) {
    int i = -1;
	AForm *iter = NULL;
    string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    while (++i < 3) {
        if (form == formTypes[i])
            break;
	}
	switch (i) {
		case 0:
			cout << "Intern creates " << form << " form." << endl;
			iter = new ShrubberyCreationForm(target);
			break;
		case 1:
			cout << "Intern creates " << form << " form." << endl;
			iter = new RobotomyRequestForm(target);
			break;
		case 2:
			cout << "Intern creates " << form << " form." << endl;
			iter = new PresidentialPardonForm(target);
			break;
		default:
			throw (Intern::UnknowForm());
	}
    return iter;
}

const char* Intern::UnknowForm:: what() const throw() {
	return "Unknown form name.";
}