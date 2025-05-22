#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

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
    
    // Create intern and bureaucrats
    Intern intern;
    Bureaucrat highGrade("Alice", 1);
    Bureaucrat midGrade("Bob", 50);
    Bureaucrat lowGrade("Charlie", 150);
y();
    cout << highGrade << endl;
    cout << midGrade << endl;
    cout << lowGrade << endl;
y();

    // Test valid form creation
    cout << "\033[1;31m--- INTERN FORM CREATION TESTS ---\033[0m" << endl;
    try {
        AForm *shrub = intern.makeForm("shrubbery creation", "garden");
        cout << *shrub << endl;
        highGrade.signForm(*shrub);
        b(shrub->getIsSigned());
        highGrade.executeForm(*shrub);
        delete shrub;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    try {
        AForm *robot = intern.makeForm("robotomy request", "target1");
        cout << *robot << endl;
        highGrade.signForm(*robot);
        b(robot->getIsSigned());
        highGrade.executeForm(*robot);
        delete robot;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    try {
        AForm *pardon = intern.makeForm("presidential pardon", "criminal");
        cout << *pardon << endl;
        highGrade.signForm(*pardon);
        b(pardon->getIsSigned());
        highGrade.executeForm(*pardon);
        delete pardon;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    // Test invalid form creation
    cout << "\033[1;35m--- INVALID FORM CREATION TESTS ---\033[0m" << endl;
    try {
        AForm *invalid = intern.makeForm("invalid form", "target");
        cout << *invalid << endl;
        delete invalid;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    try {
        AForm *empty = intern.makeForm("", "target");
        cout << *empty << endl;
        delete empty;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    // Test grade validation with intern-created forms
    cout << "\033[1;36m--- GRADE VALIDATION TESTS ---\033[0m" << endl;
    try {
        AForm *presidentialForm = intern.makeForm("presidential pardon", "test_target");
        cout << *presidentialForm << endl;
        
        // Test with insufficient grade for signing (50 > 25)
        midGrade.signForm(*presidentialForm);
        b(presidentialForm->getIsSigned());
        
        delete presidentialForm;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    // Test execution without signing
    cout << "\033[1;37m--- EXECUTION WITHOUT SIGNING TESTS ---\033[0m" << endl;
    try {
        AForm *unsignedForm = intern.makeForm("shrubbery creation", "unsigned");
        highGrade.executeForm(*unsignedForm);
        delete unsignedForm;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    // Test multiple forms from same intern
    cout << "\033[1;38m--- MULTIPLE FORM CREATION TESTS ---\033[0m" << endl;
    try {
        AForm *form1 = intern.makeForm("shrubbery creation", "location1");
        AForm *form2 = intern.makeForm("robotomy request", "location2");
        AForm *form3 = intern.makeForm("presidential pardon", "location3");
        
        cout << "Created " << form1->getName() << " for " << endl;
        cout << "Created " << form2->getName() << " for " << endl;
        cout << "Created " << form3->getName() << " for " << endl;
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();

    // Test case sensitivity
    cout << "\033[1;39m--- CASE SENSITIVITY TESTS ---\033[0m" << endl;
    try {
        AForm *form = intern.makeForm("Shrubbery Creation", "test");
        delete form;
    }
    catch (const exception &e) {
        r(e.what());
    }
    
    try {
        AForm *form = intern.makeForm("ROBOTOMY REQUEST", "test");
        delete form;
    }
    catch (const exception &e) {
        r(e.what());
    }
y();
}
