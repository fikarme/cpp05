#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructor called." << endl;
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name){
    cout << "Bureaucrat constructor called." << endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade){
	cout << "Bureaucrat copy constructor called." << endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oper){
	cout << "Bureaucrat assignation operator called." << endl;
	if (this != &oper)
		this->_grade = oper._grade;
	return (*this);
}

string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::increment(){
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement(){
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too low.");
}

ostream &operator<<(ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

void Bureaucrat::signForm(Form &f) {
    if (f.getIsSigned()) {
        cout << this->_name << " couldn't sign " << f.getName() << " because " << "the form is already signed." << endl;
        return ;
    }
    try 
    {
        f.beSigned(*this);
        cout << this->_name << " signed " << f.getName() << endl;
    }
    catch (const exception &e)
    {
        cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << endl;
    }
}