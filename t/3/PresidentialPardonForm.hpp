#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const string &target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif