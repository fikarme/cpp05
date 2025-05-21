#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    std::cout << "Bureaucrat constructor called." << std::endl;
    try {
        if (grade > 150)
            throw (GradeTooLowException());
        else if (grade < 1)
            throw (GradeTooHighException());
        else
            this->grade = grade;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::increment() {
    this->grade--;
    
    try {
        if (grade < 1)
            throw(GradeTooHighException());
    } catch (const std::exception &e) {
        this->grade++;
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::decrement() {
    this->grade++;
    
    try {
        if (grade > 150)
            throw(GradeTooLowException());
    } catch (const std::exception &e) {
        this->grade--;
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &f) {
    if (f.getIsSigned()) {
        std::cout << this->name << " couldn't sign " << f.getName() <<" because " << "the form is already signed." << std::endl;
        return ;
    }
    try {
        f.beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->name << " couldn't sign " << f.getName() <<" because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name) {
    std::cout << "Bureaucrat copy constructor is called." << std::endl;
    this->grade = cpy.grade;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &cpy) {
    std::cout << "Bureaucrat copy assignment constructor is called." << std::endl;
    this->grade = cpy.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

std::ostream &operator << (std::ostream &output, const Bureaucrat &b)
{
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return output;
}