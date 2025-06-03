# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

        void execute(const Bureaucrat &executor) const;

        std::string getTarget() const ;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif