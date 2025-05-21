#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat mucox("Muco", 1);
    Bureaucrat esadx("Esad", 1);
    Bureaucrat fikarmex("Akif", 151);
    Bureaucrat bot1("Bot1", 0);
    Bureaucrat bot2("Bot2", -12);

    
    std::cout << "\033[1;33m--------------------------------------------------------\033[0m" << std::endl;
    std::cout << mucox.getName() << " - " << mucox.getGrade() << std::endl;
    esadx.increment();
    mucox.decrement();
    RobotomyRequestForm temp("Temp");
    esadx.executeForm(temp);
    std::cout << esadx << std::endl;
    std::cout << mucox << std::endl << std::endl;

    std::cout << "\033[1;31m----- SHRUBBERY FORM -----\033[0m" << std::endl;
    ShrubberyCreationForm a("formA");
    std::cout << a << std::endl;
    a.execute(mucox);
    mucox.signForm(a);
    a.execute(mucox);
    std::cout << a.getIsSigned() << std::endl;

    std::cout << "\033[1;32m----- ROBOTOMY FORM -----\033[0m" << std::endl;
    RobotomyRequestForm b("formB");
    std::cout << b << std::endl;
    mucox.signForm(b);
    b.execute(mucox);

    std::cout << "\033[1;34m----- PRESIDENTIAL PARDON FORM -----\033[0m" << std::endl;
    PresidentialPardonForm c("formC");
    std::cout << c << std::endl;
    mucox.signForm(c);
    c.execute(mucox);
    std::cout << "\033[1;33m--------------------------------------------------------\033[0m" << std::endl;
}