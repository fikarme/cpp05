#include "Intern.hpp"

Intern ::Intern() {}

Intern ::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string aforms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && name != aforms[i])
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << name << " form." << std::endl;
		return new ShrubberyCreationForm(target);
	case 1:
		std::cout << "Intern creates " << name << " form." << std::endl;
		return new RobotomyRequestForm(target);
	case 2:
		std::cout << "Intern creates " << name << " form." << std::endl;
		return new PresidentialPardonForm(target);
	default:
		throw Intern::FormException();
	}
	return NULL;
}

const char *Intern::FormException::what() const throw()
{
	return "Form not found";
}