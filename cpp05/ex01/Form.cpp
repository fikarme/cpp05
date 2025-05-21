#include "Form.hpp"

Form::~Form() {
	cout << "Form destructor called." << endl;
}

Form::Form() : _name(""), _signGrade(150), _execGrade(150), _isSigned(false) {
    cout << "Form constructor is called." << endl;
}

Form::Form(string n, int sg, int eg) : _name(n), _signGrade(sg), _execGrade(eg), _isSigned(false) {
    cout << "Form constructor is called." << endl;
    try
    {
        if (sg < 1 || eg < 1)
            throw (GradeTooHighException());
        else if (sg > 150 || eg > 150)
            throw (GradeTooLowException());
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

Form::Form(const Form &cpy) : _name(cpy._name),  _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {
    cout << "Form copy constructor is called." << endl;
}

Form &Form::operator=(const Form &cpy) {
    if (this != &cpy)
    	this->_isSigned = cpy._isSigned;
    cout << "Form copy assignment constructor is called." << endl;
    return (*this);
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGrade())
        throw(GradeTooLowException());
    this->_isSigned = true;
}

string Form::getName() const {
    return (this->_name);
}

int Form::getGrade() const {
    return (this->_signGrade);
}

int Form::getExecGrade() const {
    return (this->_execGrade);
}

bool Form::getIsSigned() const {
    return (this->_isSigned);
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

ostream &operator<<(ostream &output, const Form &f) {
    output << "Form Name: " << f.getName() << endl;
    output << "Sign Grade: " << f.getGrade() << endl;
    output << "Execute Grade: " << f.getExecGrade() << endl;
    output << "Is Signed: " << f.getIsSigned() << endl;
    return output;
}