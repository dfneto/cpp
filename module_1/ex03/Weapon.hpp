#ifndef WEAPON_HPP
#define WEAPON_HPP

#include	<string>

class Weapon {
    std::string _type;

    public:
		Weapon(std::string type);
        std::string const	getType() const;
        void				setType(std::string type);
};

#endif
