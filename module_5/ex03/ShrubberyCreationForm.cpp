#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("no target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
    AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
        : AForm(src), target(src.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    (void)form;
    return *this;
}

void ShrubberyCreationForm::doExecute() const {
    std::ofstream myFile((this->target + "_shrubbery").c_str(), std::ios::out | std::ios::app);
    if (myFile.is_open()) {
        myFile 
		<< "     #\n"
		<< "    ###\n"
		<< "   #####\n"
		<< "  #######\n"
		<< " #########\n"
		<< "    |@|\n"
		<< "    |@|\n\n";
		myFile.close();
    } else 
        std::cerr << "Unabel to open the file: " << this->target << "_shrubbery" << std::endl;
}
