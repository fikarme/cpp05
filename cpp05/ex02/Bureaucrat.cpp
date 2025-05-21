#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructor called." << endl;
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name){
    cout << "Bureaucrat constructor with parameters is called." << endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade){
	cout << "Bureaucrat copy constructor is called." << endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oper){
    cout << "Bureaucrat copy assignment operator is called." << endl;
    if (this != &oper)
    {
        this->_grade = oper._grade;
    }
    return (*this);
}

string Bureaucrat::getName() const{
    return (this->_name);
}

int Bureaucrat::getGrade() const{
    return (this->_grade);
}

void Bureaucrat::increment(){
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrement(){
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat grade too low.");
}

ostream &operator << (ostream &output, const Bureaucrat &b){
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (output);
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        cout << this->_name << " signed " << f.getName() << endl;
    }
    catch (exception &e) {
        cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << endl;
    }
}

void Bureaucrat::executeForm(AForm const &f) {
    try {
        f.execute(*this);
        // cout << this->_name << " executed " << f.getName() << endl; // This line is moved to AForm::execute
    }
    catch (exception &e) {
        // Error messages are handled within AForm::execute or its derived classes
        // cout << this->_name << " couldn't execute " << f.getName() << " because " << e.what() << endl;
    }
}