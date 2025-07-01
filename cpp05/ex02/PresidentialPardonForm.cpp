#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") 
{
    std::cout << "PresidentialPardonForm default constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
    std::cout << "PresidentialPardonForm constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PresidentialPardonForm destructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
    : AForm(obj), _target(obj._target) 
{
    std::cout << "PresidentialPardonForm copy constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) 
{
    if (this != &obj) {
        AForm::operator=(obj);
        _target = obj._target;
    }
    std::cout << "PresidentialPardonForm assignment operator called for target: " << _target << std::endl;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const 
{
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    if (!isSigned()) {
        throw AFormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
