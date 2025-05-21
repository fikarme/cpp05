#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &cpy);
        void execute(Bureaucrat const &executor) const;
        ~RobotomyRequestForm();
};

#endif