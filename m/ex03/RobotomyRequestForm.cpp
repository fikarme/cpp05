#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy) {}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &cpy) {
    this->target = cpy.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
    std::cout << "Zzzz... zzz. ";
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}