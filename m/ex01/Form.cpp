#include "Form.hpp"

Form::Form() : name(""), signGrade(150), execGrade(150){
    isSigned = false;
    std::cout << "Form constructor is called." << std::endl;
}

Form::Form(std::string n, int sg, int eg) : name(n), signGrade(sg), execGrade(eg) {
    this->isSigned = false;
    try {
        if (sg < 1 || eg < 1)
            throw (GradeTooHighException());
        else if (sg > 150 || eg > 150)
            throw (GradeTooLowException());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Form constructor is called." << std::endl;
}

std::string Form::getName() const {
    return (this->name);
}

int Form::getGrade() const {
    return (this->signGrade);
}


int Form::getExecGrade() const {
    return (this->execGrade);
}

bool Form::getIsSigned() const {
    return (this->isSigned);
}

Form::Form(const Form &cpy) : name(cpy.name), isSigned(cpy.isSigned), signGrade(cpy.signGrade), execGrade(cpy.execGrade) {
    *this = cpy;
    std::cout << "Form copy constructor is called." << std::endl;
}

Form &Form::operator = (const Form &cpy) {
    std::cout << "Form copy assignment constructor is called." << std::endl;
    if (this != &cpy) {
    	this->isSigned = cpy.isSigned;
	}
    return (*this);
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGrade())
        throw(GradeTooLowException());
    this->isSigned = true;
}

Form::~Form() {
	std::cout << "Form destructor called." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

std::ostream &operator << (std::ostream &output, const Form &f)
{
    output << f.getName() << " Form: sign grade " << f.getGrade() 
        << ", execute grade " << f.getExecGrade() << ", form is signed " << f.getIsSigned() << ".";
    return output;
}