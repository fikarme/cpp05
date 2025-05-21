#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
		Intern someRandomIntern;
		AForm *robotomy_form = someRandomIntern.makeForm("robotomy request", "Esadx");
		AForm *presidential_form = someRandomIntern.makeForm("presidential pardon", "Fikarmex");
       
        std::cout << std::endl;
		Bureaucrat mucox("Muco", 23);

        std::cout << mucox << std::endl << std::endl;
        std::cout << *robotomy_form << std::endl;
        robotomy_form->beSigned(mucox);
        robotomy_form->execute(mucox);
        std::cout << std::endl;

        std::cout << *presidential_form << std::endl;
        presidential_form->beSigned(mucox);
        presidential_form->execute(mucox);
        std::cout << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}