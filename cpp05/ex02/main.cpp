#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    cout << "\033[1;33m---\033[0m" << endl;
    cout << "\033[1;31m--- SHRUBBERY FORM ---\033[0m" << endl;
    try {
        ShrubberyCreationForm f("formA");
        cout << f << endl;
        Bureaucrat b("shruB", 1);
        cout << b << endl;
        b.signForm(f);
        f.executeForm(b);
    a.execute(mucox);
    mucox.signForm(a);
    a.execute(mucox);
    cout << a.getIsSigned() << endl;
    cout << endl;

    cout << "\033[1;32m--- ROBOTOMY FORM ---\033[0m" << endl;
    RobotomyRequestForm b("formB");
    cout << b << endl;
    mucox.signForm(b);
    b.execute(mucox);
    cout << endl;

    cout << "\033[1;34m--- PRESIDENTIAL FORM ---\033[0m" << endl;
    PresidentialPardonForm c("formC");
    cout << c << endl;
    mucox.signForm(c);
    c.execute(mucox);
    cout << "\033[1;33m---\033[0m" << endl;
}