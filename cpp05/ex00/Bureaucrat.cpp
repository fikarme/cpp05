#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructor called." << endl;
}

// If an exception is thrown, _name is already initialized but _grade is uninitialized.
// However, this is fine because:
// Exception prevents object creation
// No destructor is called
// No partially constructed object exists

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

// Returns ostream& to enable chaining: cout << b1 << b2 << endl;
// but how?
ostream &operator<<(ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}