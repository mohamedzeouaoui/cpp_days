#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("Default")
{
    std::cout << "Default constructor called for ShrubberyCreationForm: " << _target << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "Constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target)
{
    std::cout << "Copy constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj); // Call base class assignment operator
        _target = obj._target; // Copy target
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Creating shrubbery at " << _target << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << "ShrubberyCreationForm: " << form.getName()
       << ", Target: " << form.getTarget()
       << ", Signed: " << form.isSigned()
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
