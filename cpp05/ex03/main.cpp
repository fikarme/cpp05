#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
    
    Intern intern;
    Bureaucrat highGrade("Alice", 1);
    Bureaucrat midGrade("Bob", 50);
    Bureaucrat lowGrade("Charlie", 150);
y();
    cout << highGrade << endl;
    cout << midGrade << endl;
    cout << lowGrade << endl;
y();
    cout << "\033[1;31m--- INTERN FORM CREATION TESTS ---\033[0m" << endl;
    AForm *shrub = NULL;
    try {
        shrub = intern.makeForm("shrubbery creation", "garden");
        cout << *shrub << endl;
        highGrade.signForm(*shrub);
        b(shrub->getIsSigned());
        highGrade.executeForm(*shrub);
    }
    catch (const exception &e) {r(e.what());}
    delete shrub;

y();
    AForm *robot = NULL;
    try {
        robot = intern.makeForm("robotomy request", "target1");
        cout << *robot << endl;
        highGrade.signForm(*robot);
        b(robot->getIsSigned());
        highGrade.executeForm(*robot);
    }
    catch (const exception &e) {r(e.what());}
    delete robot;

y();
    AForm *pardon = NULL;
    try {
        pardon = intern.makeForm("presidential pardon", "criminal");
        cout << *pardon << endl;
        highGrade.signForm(*pardon);
        b(pardon->getIsSigned());
        highGrade.executeForm(*pardon);
    }
    catch (const exception &e) {r(e.what());}
    delete pardon;
y();
    cout << "\033[1;35m--- INVALID FORM CREATION TESTS ---\033[0m" << endl;
    AForm *invalid = NULL;
    try {
        invalid = intern.makeForm("invalid form", "target");
        cout << *invalid << endl;
    }
    catch (const exception &e) {r(e.what());}
    delete invalid;
y();
    AForm *empty = NULL;
    try {
        empty = intern.makeForm("", "target");
        cout << *empty << endl;
    }
    catch (const exception &e) {r(e.what());}
    delete empty;
y();
    cout << "\033[1;36m--- GRADE VALIDATION TESTS ---\033[0m" << endl;
    AForm *presidentialForm = NULL;
    try {
        presidentialForm = intern.makeForm("presidential pardon", "test_target");
        cout << *presidentialForm << endl;
        
        midGrade.signForm(*presidentialForm);
        b(presidentialForm->getIsSigned());
    }
    catch (const exception &e) {r(e.what());}
    delete presidentialForm;
y();
    cout << "\033[1;37m--- EXECUTION WITHOUT SIGNING TESTS ---\033[0m" << endl;
    AForm *unsignedForm = NULL;
    try {
        unsignedForm = intern.makeForm("shrubbery creation", "unsigned");
        highGrade.executeForm(*unsignedForm);
    }
    catch (const exception &e) {r(e.what());}
    delete unsignedForm;
y();
    cout << "\033[1;38m--- MULTIPLE FORM CREATION TESTS ---\033[0m" << endl;
    AForm *formArray[3] = {NULL, NULL, NULL};
    try {
        formArray[0] = intern.makeForm("shrubbery creation", "location1");
        formArray[1] = intern.makeForm("robotomy request", "location2");
        formArray[2] = intern.makeForm("presidential pardon", "location3");
        cout << *formArray[0] << endl;
        cout << *formArray[1] << endl;
        cout << *formArray[2] << endl;
    }
    catch (const exception &e) {r(e.what());}
    delete formArray[0];
    delete formArray[1];
    delete formArray[2];
y();
    cout << "\033[1;39m--- CASE SENSITIVITY TESTS ---\033[0m" << endl;
    AForm *caseSensitiveForm = NULL;
    try {
        caseSensitiveForm = intern.makeForm("Shrubbery Creation", "test");
    }
    catch (const exception &e) {r(e.what());}
    delete caseSensitiveForm;
    
    AForm *caseSensitiveForm2 = NULL;
    try {
        caseSensitiveForm2 = intern.makeForm("ROBOTOMY REQUEST", "test");
    }
    catch (const exception &e) {r(e.what());}
    delete caseSensitiveForm2;
y();
}
