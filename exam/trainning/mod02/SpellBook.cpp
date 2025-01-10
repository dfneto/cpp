#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &ref) {
	if (this != &ref)
		*this = ref;
}

SpellBook& SpellBook::operator=(const SpellBook &ref) {
	this->spellBook = ref.spellBook;
	return *this;
}

SpellBook::~SpellBook() {}

void    SpellBook::learnSpell(ASpell *spell) {
	if (spell)
		if (spellBook.find(spell->getName()) == spellBook.end())
			spellBook[spell->getName()] = spell->clone();
}

void    SpellBook::forgetSpell(const std::string &name) {
	if (spellBook.find(name) != spellBook.end()){
		delete spellBook[name];
		spellBook.erase(spellBook.find(name));
	}
}

ASpell* SpellBook::createSpell(const std::string &name) {
	ASpell *tmp = NULL;
	if (spellBook.find(name) != spellBook.end())
		tmp = spellBook[name];
	return tmp;
}

