#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &cpy) {
    if (this != &cpy)
        this->_target = cpy._target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
    cout << "Zzzz... zzz. ";
    if (rand() % 2 == 0)
        cout << this->_target << " has been robotomized successfully." << endl;
    else
        cout << this->_target << " robotomy failed." << endl;
}