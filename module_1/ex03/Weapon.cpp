#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

std::string const Weapon::getType() const {
    return _type;
}

void	Weapon::setType(std::string type) {
	_type = type;
}