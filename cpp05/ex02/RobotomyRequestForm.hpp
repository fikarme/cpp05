#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

using std::rand;

class RobotomyRequestForm : public AForm {
    private:
        string _target;
    public:
        ~RobotomyRequestForm();
        RobotomyRequestForm(string target);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
        void execute(Bureaucrat const &executor) const;
};

#endif