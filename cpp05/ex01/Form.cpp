#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called for Form: " << _name << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "Copy constructor called for Form: " << _name << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called for Form: " << _name << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Signed: " << form.isSigned()
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void Form::execute(const Bureaucrat &executor) const
{
    if (!this->_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
}

const char* Form::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
    return "Form is already signed";
}
