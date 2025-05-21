#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const string &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};

#endif