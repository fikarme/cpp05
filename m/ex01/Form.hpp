#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form();
        Form(std::string n, int sg, int eg);
        Form(const Form &cpy);
        std::string getName() const;
        int getGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;
		Form& operator = (Form const &cpy);
        void beSigned(const Bureaucrat &b);
        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
        ~Form();
};

std::ostream &operator << (std::ostream &output, const Form &f);

#endif