#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-----------------------Shrubbery-------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "--- TEST 1 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("shrubbery_bureaucrat", 137);
			ShrubberyCreationForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("shrubbery_bureaucrat", 145);
			ShrubberyCreationForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("shrubbery_bureaucrat", 146);
			ShrubberyCreationForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "------------------------Robotomy--------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "--- TEST 1 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("robotomy_bureaucrat", 45);
			RobotomyRequestForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("robotomy_bureaucrat", 72);
			RobotomyRequestForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("robotomy_bureaucrat", 73);
			RobotomyRequestForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "-----------------------Presidential-----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "--- TEST 1 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("presidential_bureaucrat", 5);
			PresidentialPardonForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("presidential_bureaucrat", 25);
			PresidentialPardonForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3 ---" << std::endl;
	{
		try
		{
			Bureaucrat b("presidential_bureaucrat", 26);
			PresidentialPardonForm f("target");

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

			b.signForm(f);
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}