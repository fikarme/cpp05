#include "Bureaucrat.hpp"

inline void y() {
    cout << "\033[1;33m ---------\033[0m" << endl;
}

inline void r(const char *msg) {
    cout << "\033[1;31m ---- "<< msg << " -----\033[0m" << endl;
}

int main() {
    Bureaucrat b("buro", 1);
    Bureaucrat c("curo", 150);
    cout << b.getName() << endl;
    cout << b.getGrade() << endl;
	cout << b << endl;
y();
    b.decrement();
    cout << b.getGrade() << endl;
    b.increment();
    cout << b.getGrade() << endl;
y();
    try {Bureaucrat inaf("isinaf", 42);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat inaf("isinaf", 151);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat inaf("isinaf", 0);}
    catch (const exception &e) {r(e.what());}
    try {Bureaucrat neg("negative", -12);}
    catch (const exception &e) {r(e.what());}
    try {b.increment();}
	catch (const exception &e) {r(e.what());}
    try {c.decrement();}
	catch (const exception &e) {r(e.what());}
y();
}