#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");

    if (form) {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    AForm* unknown = someRandomIntern.makeForm("wrong form", "Nowhere");
    if (unknown)
        delete unknown;

    return 0;
}
