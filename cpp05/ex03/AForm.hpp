#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class AForm {
    private:
        const string    _name;
        const int       _signGrade;
        const int       _execGrade;
        bool            _isSigned;
    public:
        ~AForm();
        AForm();
        AForm(string n, int sg, int eg);
        AForm(const AForm &cpy);
		AForm&operator=(AForm const &cpy);

        string  getName() const;
        int     getGrade() const;
        int     getExecGrade() const;
        bool    getIsSigned() const;
        void    beSigned(const Bureaucrat &b);

        class GradeTooHighException : public exception {
            const char* what() const throw();
        };
        class GradeTooLowException : public exception {
            const char* what() const throw();
        };
        class AFormNotSigned : public exception {
            const char* what() const throw();
        };
        virtual void execute(Bureaucrat const &executor) const = 0;

};

ostream &operator<<(ostream &output, const AForm &f);

#endif