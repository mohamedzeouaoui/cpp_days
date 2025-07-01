#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), 
    _target("default_target") 
{
    std::cout << "ShrubberyCreationForm default constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
    std::cout << "ShrubberyCreationForm constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "ShrubberyCreationForm destructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) 
    : AForm(obj), _target(obj._target) 
{
    std::cout << "ShrubberyCreationForm copy constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) 
{
    if (this != &obj) {
        AForm::operator=(obj);
        _target = obj._target;
    }
    std::cout << "ShrubberyCreationForm assignment operator called for target: " << _target << std::endl;
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const 
{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    if (!isSigned()) {
        throw AFormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    file << "ASCII Art of a shrubbery for target: " << _target << std::endl;
    file << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    file.close();

    std::cout << "Shrubbery created for target: " << _target << std::endl;
}


