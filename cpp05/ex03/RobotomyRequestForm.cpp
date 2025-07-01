#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") 
{
    std::cout << "RobotomyRequestForm default constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "RobotomyRequestForm constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm destructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
    : AForm(obj), _target(obj._target) 
{
    std::cout << "RobotomyRequestForm copy constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) 
{
    if (this != &obj) {
        AForm::operator=(obj);
        _target = obj._target;
    }
    std::cout << "RobotomyRequestForm assignment operator called for target: " << _target << std::endl;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const 
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    if (!isSigned()) {
        throw AFormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "Bzzzzz... Vrrrrrrr...\n";

    std::cout << "RobotomyRequestForm executed for target: " << _target << std::endl;
    if (rand() % 2) {
        std::cout << "RobotomyRequestForm successful for target: " << _target << std::endl;
    } else {
        std::cout << "RobotomyRequestForm failed for target: " << _target << std::endl;
    }
}
