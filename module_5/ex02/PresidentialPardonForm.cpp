#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("no target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
    AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
        : AForm(src), target(src.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
    (void)form;
    return *this;
}

void PresidentialPardonForm::doExecute() const {
    std::cout << "Breaking news: "
	<< target
	<< " receives a formal pardon, signifying absolution from their past actions and a fresh start endorsed by Zaphod Beeblebrox!"
	<< std::endl;
}
