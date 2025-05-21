#include "AForm.hpp"

AForm::AForm() : name(""), signGrade(150), execGrade(150){
    isSigned = false;
    std::cout << "AForm constructor is called." << std::endl;
}

AForm::AForm(std::string n, int sg, int eg) : name(n), signGrade(sg), execGrade(eg) {
    this->isSigned = false;
    try {
        if (sg < 1 || eg < 1)
            throw (GradeTooHighException());
        else if (sg > 150 || eg > 150)
            throw (GradeTooLowException());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "AForm constructor is called." << std::endl;
}

std::string AForm::getName() const {
    return (this->name);
}

int AForm::getGrade() const {
    return (this->signGrade);
}


int AForm::getExecGrade() const {
    return (this->execGrade);
}

bool AForm::getIsSigned() const {
    return (this->isSigned);
}

AForm::AForm(const AForm &cpy) : name(cpy.name), isSigned(cpy.isSigned), signGrade(cpy.signGrade), execGrade(cpy.execGrade) {
    *this = cpy;
    std::cout << "AForm copy constructor is called." << std::endl;
}

AForm &AForm::operator = (const AForm &cpy) {
    std::cout << "AForm copy assignment constructor is called." << std::endl;
    if (this != &cpy) {
    	this->isSigned = cpy.isSigned;
	}
    return (*this);
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGrade())
        throw(GradeTooLowException());
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    try {
        if (this->isSigned == false)
            throw(FormNotSigned());
        else if (executor.getGrade() > this->execGrade)
            throw(GradeTooLowException());
        std::cout << executor.getName() << ", executed the " << this->getName() << "." << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

AForm::~AForm() {
	std::cout << "AForm destructor called." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

const char* AForm::FormNotSigned::what() const throw() {
    return ("The form is not signed.");
}

std::ostream &operator << (std::ostream &output, const AForm &f)
{
    output << f.getName() << " Form: sign grade " << f.getGrade() 
        << ", execute grade " << f.getExecGrade() << ", form is signed " << f.getIsSigned() << ".";
    return output;
}