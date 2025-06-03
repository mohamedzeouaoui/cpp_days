#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("Default")
{
    std::cout << "Default constructor called for PresidentialPardonForm: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
    std::cout << "Constructor called for PresidentialPardonForm: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called for PresidentialPardonForm: " << _target << std::endl;
}



PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj); // Call base class assignment operator
        _target = obj._target; // Copy target
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const 
{
    return _target;
}


std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
    os << "PresidentialPardonForm: " << form.getName()
       << ", Target: " << form.getTarget()
       << ", Signed: " << form.isSigned()
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}