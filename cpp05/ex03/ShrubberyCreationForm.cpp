#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy) {
    this->_target = cpy._target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
    ofstream file((this->_target + "_shrubbery").c_str());

    file << "           %%%,%%%%%%%" << endl
         << "           ,'%% \\-*%%%%%%%" << endl
         << "     ;%%%%%*%   _%%%%\"" << endl
         << "      ,%%%       \\(_.*%%%%." << endl
         << "      % *%%, ,%%%%*(    '" << endl
         << "    %^     ,*%%% )\\|,%%*%,_" << endl
         << "         *%    \\/ #).-\"*%%*" << endl
         << "             _.) ,/ *%," << endl
         << "     _________/)#(_____________" << endl;
    file.close();
}