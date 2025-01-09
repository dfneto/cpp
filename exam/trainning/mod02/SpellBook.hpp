
#pragma once

#include <map> 
#include <iostream>
#include "ASpell.hpp"

class SpellBook {
	private:
		std::map<std::string, ASpell *> spellBook;

		SpellBook(const SpellBook &);
		SpellBook & operator=(const SpellBook &);

	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *);
		void	forgetSpell(const std::string &);
		ASpell*	createSpell(const std::string &);

};
