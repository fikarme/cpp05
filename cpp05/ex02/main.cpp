#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

inline void y() {
    cout << "\033[1;33m ---------\033[0m" << endl;
}

inline void r(const char *msg) {
    cout << "\033[1;31m ---- "<< msg << " -----\033[0m" << endl;
}

inline void b(bool b) {
    if (b)
        cout << "\033[1;32m true\033[0m" << endl;
    else
        cout << "\033[1;34m false\033[0m" << endl;
}

int main() {
    srand(time(NULL));
    
    Bureaucrat highGrade("Alice", 1);
    Bureaucrat midGrade("Bob", 50);
    Bureaucrat lowGrade("Charlie", 150);
y();
    cout << highGrade << endl;
    cout << midGrade << endl;
    cout << lowGrade << endl;
y();
    cout << "\033[1;31m--- SHRUBBERY FORM TESTS ---\033[0m" << endl;
    ShrubberyCreationForm shrub("garden");
    cout << shrub << endl;
    highGrade.signForm(shrub);
    b(shrub.getIsSigned());
    highGrade.executeForm(shrub);
y();
    ShrubberyCreationForm shrub2("home");
    lowGrade.signForm(shrub2); // Should fail (150 > 145)
    b(shrub2.getIsSigned());
y();
    cout << "\033[1;32m--- ROBOTOMY FORM TESTS ---\033[0m" << endl;
    RobotomyRequestForm robot("target1");
    cout << robot << endl;
    highGrade.signForm(robot);
    b(robot.getIsSigned());
    highGrade.executeForm(robot);
y();
    RobotomyRequestForm robot2("target2");
    midGrade.signForm(robot2); // Should succeed (50 < 72)
    b(robot2.getIsSigned());
    midGrade.executeForm(robot2); // Should fail (50 > 45)
y();
    cout << "\033[1;34m--- PRESIDENTIAL FORM TESTS ---\033[0m" << endl;
    PresidentialPardonForm pardon("criminal");
    cout << pardon << endl;
    highGrade.signForm(pardon);
    b(pardon.getIsSigned());
    highGrade.executeForm(pardon);
y();
    PresidentialPardonForm pardon2("another_criminal");
    midGrade.signForm(pardon2); // Should fail
    b(pardon2.getIsSigned());
y();
    cout << "\033[1;35m--- INVALID FORM TESTS ---\033[0m" << endl;
    try {ShrubberyCreationForm invalid1("");}
    catch (const exception &e) {r(e.what());}
y();
    cout << "\033[1;36m--- INVALID BUREAUCRAT TESTS ---\033[0m" << endl;
    try {Bureaucrat tooLow("TooLow", 151);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat tooHigh("TooHigh", 0);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat negative("Negative", -42);}
    catch (const exception &e) {r(e.what());}
y();
    cout << "\033[1;37m--- EXECUTION WITHOUT SIGNING TESTS ---\033[0m" << endl;
    try {
        ShrubberyCreationForm unsignedForm("unsigned");
        highGrade.executeForm(unsignedForm); // Should fail - not signed
    }
    catch (const exception &e) {r(e.what());}
y();
    cout << "\033[1;38m--- GRADE MODIFICATION TESTS ---\033[0m" << endl;
    Bureaucrat testBureaucrat("Test", 2);
    cout << testBureaucrat << endl;
    testBureaucrat.increment(); // Should become grade 1
    cout << testBureaucrat << endl;
    try {
        testBureaucrat.increment(); // Should fail (can't go below 1)
    }
    catch (const exception &e) {r(e.what());}
y();
    Bureaucrat testBureaucrat2("Test2", 149);
    cout << testBureaucrat2 << endl;
    testBureaucrat2.decrement(); // Should become grade 150
    cout << testBureaucrat2 << endl;
    try {
        testBureaucrat2.decrement(); // Should fail (can't go above 150)
    }
    catch (const exception &e) {r(e.what());}
y();
}