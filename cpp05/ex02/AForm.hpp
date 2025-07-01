#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        AForm();
        AForm(const AForm &obj);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();

        AForm &operator=(const AForm &obj);
    
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const = 0;
    
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
    
        class AFormNotSignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
    
        class AFormAlreadySignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif