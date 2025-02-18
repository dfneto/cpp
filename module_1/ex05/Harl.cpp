#include "Harl.hpp"

void Harl::_debug() {
	std::cout << "[DEBUG] I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;   
};

void Harl::_info() {
	std::cout << "[INFO] I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
};
    
void Harl::_warning() {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
};
    
void Harl::_error() {
	std::cout << "[ERROR] This is unacceptable, I want to speak to the manager now." << std::endl;
};

void    Harl::complain(std::string level) {
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// Assigning pointer-to-member-function
	// No caso eu tenho um array com 4 ponteiros, cada um para o endereco de uma funcao.
	void (Harl::*functions[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++) {
		if (level == names[i])
			// Calling the member function using pointer to object and pointer-to-member-function
			(this->*functions[i])();
	}
}
//void (Harl::*)(void) is a pointer to a member function of Harl takes no arguments and returns void
//functions[4] – An Array of Member Function Pointers.
//Each element in functions[] must match the type void (Harl::*)(void), which is a pointer to a member function of Harl
/*
(this->*functions[i])();
functions[i] → Retrieves the function pointer stored at index i.
this->*functions[i] → Dereferences the member function pointer for the current instance.
() → Calls the function.
*/
