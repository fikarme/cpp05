#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &cpy);
        void execute(Bureaucrat const &executor) const;
        ~PresidentialPardonForm();
};

#endif