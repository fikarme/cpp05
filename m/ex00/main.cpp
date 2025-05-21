#include "Bureaucrat.hpp"

int main() {
    Bureaucrat mucox("Muco", 1);
    Bureaucrat esadx("Esad", 1);
    Bureaucrat fikarmex("Akif", 151);
    Bureaucrat bot1("Bot1", 0);
    Bureaucrat bot2("Bot2", -12);
    
    std::cout << "----------" << std::endl;
    std::cout << mucox.getName() << " - " << mucox.getGrade() << std::endl;
    std::cout << std::endl;

    esadx.increment();
    mucox.decrement();
    std::cout << esadx << std::endl;
    std::cout << mucox << std::endl;
    std::cout << "----------" << std::endl;
}