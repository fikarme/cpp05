#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Invalid grades:" << std::endl;

	try
	{
		Form f1("Form1", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	try
	{
		Form f2("Form2", 10, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	try
	{
		Form f3("Form3", 151, 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	try
	{
		Form f4("Form4", 10, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "signing forms with bureaucrats:" << std::endl;

	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		std::cout << b1 << std::endl;
		Form f5("Form5", 11, 1);
		std::cout << f5 << std::endl;

		b1.signForm(f5);

		std::cout << f5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	try
	{
		Bureaucrat b2("Bureaucrat2", 50);
		std::cout << b2 << std::endl;
		Form f6("Form6", 25, 25);
		std::cout << f6 << std::endl;

		b2.signForm(f6);

		std::cout << f6 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	try
	{
		Bureaucrat b3("Bureaucrat3", 100);
		std::cout << b3 << std::endl;
		Form f7("Form7", 75, 75);
		std::cout << f7 << std::endl;

		b3.signForm(f7);

		std::cout << f7 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	return 0;
}