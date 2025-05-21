#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm &AForm::operator=(AForm const &src)
{
	this->_signed = src._signed;
	return *this;
}

AForm::~AForm() {}

const string &AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormException::what() const throw()
{
	return "An error occurred in form processing";
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << "Form: " << f.getName() << endl
	  << "-Signed: " << f.getSigned() << endl
	  << "-Grade to sign: " << f.getGradeToSign() << endl
	  << "-Grade to execute: " << f.getGradeToExecute();
	return o;
}
