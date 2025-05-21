#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    protected:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm();
        AForm(std::string n, int sg, int eg);
        AForm(const AForm &cpy);
		AForm& operator = (AForm const &cpy);
        virtual std::string getName() const;
        virtual int getGrade() const;
        virtual int getExecGrade() const;
        virtual bool getIsSigned() const;
        virtual void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const &executor) const = 0;
        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw();
        };
        class FormNotSigned : public std::exception {
            virtual const char* what() const throw();
        };
        ~AForm();
};

std::ostream &operator << (std::ostream &output, const AForm &f);

#endif