#include "Form.hpp"

inline void y() {
    cout << "\033[1;33m ---------\033[0m" << endl;
}

// inline void r() {
//     cout << "\033[1;31m ---\033" << endl;
// }

// inline void g() {
//     cout << "\033[1;32m ---\033" << endl;
// }

// inline void b() {
//     cout << "\033[1;34m ---\033" << endl;
// }


int main() {
y();
    Bureaucrat mucox("Muco", 42);
    Bureaucrat akefx("Akef", 11);
    Bureaucrat low("low", 151);
    Bureaucrat high("high", 0);
    Bureaucrat tooHigh("tooHigh", -42);
y();
    akefx.increment();
    mucox.decrement();
y();
    cout << akefx << endl;
    cout << mucox << endl;
y();
    Form af("A", 1, 4);
    Form bf("B", 6, 9);
    cout << af << endl;
    cout << bf << endl;
y();
    mucox.signForm(af);
    akefx.signForm(af);
    akefx.signForm(af);
    cout << af.getIsSigned() << endl;
    cout << bf.getIsSigned() << endl;
y();
    Bureaucrat lowGradeBureaucrat("LowGrade", 150);
    Form cf("C", 100, 50);
    Form df("D", 1, 1);
y();
    cout << cf << endl;
    cout << df << endl;
y();
    lowGradeBureaucrat.signForm(cf);
    lowGradeBureaucrat.signForm(df);
y();
    cout << cf.getIsSigned() << endl;
    cout << df.getIsSigned() << endl;
y();
}