#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called for AForm: " << _name << std::endl;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "Copy constructor called for AForm: " << _name << std::endl;
}

AForm::~AForm()
{
    std::cout << "Destructor called for AForm: " << _name << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        // _name = obj._name;
        // _gradeToSign = obj._gradeToSign;
        // _gradeToExecute = obj._gradeToExecute;
        _isSigned = obj._isSigned;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << "AForm: " << Aform.getName() << ", Signed: " << Aform.isSigned()
       << ", Grade to Sign: " << Aform.getGradeToSign()
       << ", Grade to Execute: " << Aform.getGradeToExecute();
    return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (_isSigned)
        throw AFormAlreadySignedException();
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    if (_isSigned)
        throw AFormAlreadySignedException();
    _isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const char* AForm::AFormNotSignedException::what() const throw()
{
    return "AForm is not signed";
}

const char* AForm::AFormAlreadySignedException::what() const throw()
{
    return "AForm is already signed";
}
