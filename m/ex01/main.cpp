#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat mucox("Muco", 1);
    Bureaucrat esadx("Esad", 1);
    Bureaucrat fikarmex("Akif", 151);
    Bureaucrat bot1("Bot1", 0);
    Bureaucrat bot2("Bot2", -12);

    
    std::cout << "----------" << std::endl;
    std::cout << mucox.getName() << " - " << mucox.getGrade() << std::endl;
    esadx.increment();
    mucox.decrement();
    std::cout << esadx << std::endl;
    std::cout << mucox << std::endl;
    std::cout << "----------" << std::endl << std::endl;


    std::cout << "----- FORM -----" << std::endl;
    Form a("A", 1, 4);
    Form b("B", 6, 9);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    mucox.signForm(a);
    esadx.signForm(a);
    esadx.signForm(a);
    std::cout << a.getIsSigned() << std::endl;
    std::cout << b.getIsSigned() << std::endl;
    std::cout << "----------" << std::endl << std::endl;
}