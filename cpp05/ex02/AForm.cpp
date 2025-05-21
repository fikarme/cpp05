#include "AForm.hpp"

AForm::~AForm() {
	cout << "AForm destructor called." << endl;
}

AForm::AForm() : _name(""), _signGrade(150), _execGrade(150), _isSigned(false) {
    cout << "AForm default constructor is called." << endl;
}

AForm::AForm(string n, int sg, int eg) : _name(n), _signGrade(sg), _execGrade(eg), _isSigned(false) {
    cout << "AForm constructor with parameters is called." << endl;
    if (sg < 1 || eg < 1)
        throw GradeTooHighException();
    else if (sg > 150 || eg > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &cpy) : _name(cpy._name),  _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {
    cout << "AForm copy constructor is called." << endl;
}

AForm &AForm::operator=(const AForm &cpy) {
    cout << "AForm copy assignment operator is called." << endl;
    if (this != &cpy)
    	this->_isSigned = cpy._isSigned;
    return (*this);
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

string AForm::getName() const {
    return (this->_name);
}

int AForm::getGrade() const {
    return (this->_signGrade);
}

int AForm::getExecGrade() const {
    return (this->_execGrade);
}

bool AForm::getIsSigned() const {
    return (this->_isSigned);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

ostream &operator<<(ostream &output, const AForm &f) {
    output << f.getName() << " AForm: sign grade " << f.getGrade() 
        << ", execute grade " << f.getExecGrade() << ", Aform is signed " << f.getIsSigned() << ".";
    return output;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (this->_isSigned == false)
        throw AFormNotSigned();
    else if (executor.getGrade() > this->_execGrade)
        throw GradeTooLowException();
    // Specific execution logic will be in derived classes
    // cout << executor.getName() << ", executed the " << this->getName() << "." << endl; // Moved to derived classes
}

const char* AForm::AFormNotSigned::what() const throw() {
    return ("The form is not signed.");
}