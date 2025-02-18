#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("no target") {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
    AForm("RobotomyRequestForm", 72, 45), target(target) {
        std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) 
        : AForm(src), target(src.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
    (void)form;
    return *this;
}

void RobotomyRequestForm::doExecute() const {
    std::cout << "ratta-tat-tat-tat" << std::endl;
	if (std::rand() % 2)
		std::cout << "Robotomy successfull: " << target << " memories were wiped out!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
