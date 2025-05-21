#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const string &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

#endif