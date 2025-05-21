#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy) {
    this->_target = cpy._target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
    cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << endl;
}