#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm *form;

	std::cout << "-----------------------Robotomy Request-------------------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-----------------------Invalid Robotomy Request------------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("invalid request", "Bender");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-----------------------Presidential Pardon-----------------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("presidential pardon", "Fry");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-----------------------Invalid Presidential Pardon--------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("invalid pardon", "Fry");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-----------------------Shrubbery Creation-------------------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("shrubbery creation", "Garden");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-----------------------Invalid Shrubbery Creation----------------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("invalid shrubbery", "Garden");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}