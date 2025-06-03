#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("Default")
{
    std::cout << "Default constructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
    std::cout << "Constructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target)
{
    std::cout << "Copy constructor called for RobotomyRequestForm: " << _target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj); // Call base class assignment operator
        _target = obj._target; // Copy target
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzzzz... " << _target << " has been robotomized successfully 50% of the time!" << std::endl;
}


std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << "RobotomyRequestForm: " << form.getName()
       << ", Target: " << form.getTarget()
       << ", Signed: " << form.isSigned()
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
