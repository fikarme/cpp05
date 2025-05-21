#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class Form {
    private:
        const string    _name;
        const int       _signGrade;
        const int       _execGrade;
        bool            _isSigned;
    public:
        ~Form();
        Form();
        Form(string n, int sg, int eg);
        Form(const Form &cpy);
		Form&operator=(Form const &cpy);

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
};

ostream &operator<<(ostream &output, const Form &f);

#endif