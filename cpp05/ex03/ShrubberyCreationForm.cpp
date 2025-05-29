#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy) {
    if (this != &cpy)
        this->_target = cpy._target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
    ofstream file((this->_target + "_shrubbery").c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Could not create file");
    }

    file << "           %%%,%%%%%%%"        << endl
         << "           ,'%% \\-*%%%%%%%"   << endl
         << "     ;%%%%%*%   _%%%%\""       << endl
         << "      ,%%%       \\(_.*%%%%."  << endl
         << "      % *%%, ,%%%%*(    '"     << endl
         << "    %^     ,*%%% )\\|,%%*%,_"  << endl
         << "         *%    \\/ #).-\"*%%*" << endl
         << "             _.) ,/ *%,"       << endl
         << "     _________/)#(___________" << endl;
    file.close();
}

//SOLID Principles Analysis