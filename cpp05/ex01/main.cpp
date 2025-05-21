#include "Form.hpp"

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
    Bureaucrat mucox("Muco", 149);
    Bureaucrat akefx("Akef", 11);
y();
    akefx.increment();
    mucox.decrement();
y();
    cout << akefx << endl;
    cout << mucox << endl;
y();
    Form af("A Form", 10, 3);
    Form bf;
y();
    cout << af << endl;
    cout << bf << endl;
y();
    akefx.signForm(af);
    mucox.signForm(af);
    mucox.signForm(bf);
    b(af.getIsSigned());
    b(bf.getIsSigned());

    try {Bureaucrat low("low", 151);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat high("high", 0);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat tooHigh("tooHigh", -42);}
    catch (const exception &e) {r(e.what());}
y();
    try {Form if1("sgh", 0, 50);}
    catch (const exception &e) {r(e.what());}
    try {Form if2("egh", 50, 0);}
    catch (const exception &e) {r(e.what());}
    try {Form if3("sgl", 151, 50);}
    catch (const exception &e) {r(e.what());}
    try {Form if4("egl", 50, 151);}
    catch (const exception &e) {r(e.what());}
y();
    try {
        Form if5("sgl", 50, 50);
        Bureaucrat lowGradeBureaucrat("LowGrade", 150);
        lowGradeBureaucrat.signForm(if5);
    }
    catch (const exception &e) {r(e.what());}
    //The exercise is trying to create a specific simulation of bureaucracy
    //- where a bureaucrat handles the form signing attempt internally
    //without "bothering" higher levels with exceptions.
y();
}