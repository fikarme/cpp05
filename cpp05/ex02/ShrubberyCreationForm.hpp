#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

using std::ofstream;

class ShrubberyCreationForm : public AForm {
    private:
        string _target;
    public:
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
        void execute(Bureaucrat const &executor) const;
};

#endif