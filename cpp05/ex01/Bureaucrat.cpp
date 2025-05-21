#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructor called." << endl;
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name){
    cout << "Bureaucrat constructor called." << endl;
    try
	{
        if (grade > 150)
            throw (GradeTooLowException());
        else if (grade < 1)
            throw (GradeTooHighException());
        else
            _grade = grade;
    }
	catch (const exception &e)
	{
        cout << e.what() << endl;
    }
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
	this->_grade--;
	try
    {
		if (_grade < 1)
			throw(GradeTooHighException());
	}
    catch (const exception &e)
    {
		this->_grade++;
		cout << e.what() << endl;
	}
}

void Bureaucrat::decrement(){
	this->_grade++;
	try
    {
		if (_grade > 150)
			throw(GradeTooLowException());
	}
    catch (const exception &e)
    {
		this->_grade--;
		cout << e.what() << endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

ostream &operator << (ostream &output, const Bureaucrat &b){
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return output;
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