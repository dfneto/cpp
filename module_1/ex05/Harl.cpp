#include "Harl.hpp"

void Harl::_debug() {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;   
};

void Harl::_info() {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
};
    
void Harl::_warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
};
    
void Harl::_error() {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
};

void    Harl::complain(std::string level) {

}