#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
		Intern  someRandomIntern;
		AForm   *presidentialForm  = someRandomIntern.makeForm("presidential pardon", "fikarmex");
		AForm   *robotomyForm      = someRandomIntern.makeForm("robotomy request", "mucox");
       
        cout << endl;
		Bureaucrat mucox("mucox", 23);

        cout << mucox << endl << endl;
        cout << *robotomyForm << endl;
        cout << endl;

        robotomyForm->beSigned(mucox);
        robotomyForm->execute(mucox);
        cout << endl;

        cout << *presidentialForm << endl;
        presidentialForm->beSigned(mucox);
        presidentialForm->execute(mucox);
        cout << endl;
	}
	catch(const exception &e) {
		std::cerr << e.what() << endl;
	}
}
