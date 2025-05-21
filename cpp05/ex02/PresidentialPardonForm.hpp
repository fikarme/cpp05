#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        string _target;
    public:
        ~PresidentialPardonForm();
        PresidentialPardonForm(string target);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
        void execute(Bureaucrat const &executor) const;
};

#endif