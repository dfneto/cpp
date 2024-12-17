#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &ref) {
    *this = ref;
}

SpellBook &SpellBook::operator=(const SpellBook &ref) {
    return *this;
}

SpellBook::~SpellBook() {}

void    SpellBook::learnSpell(ASpell *spell) {
    if (spell)
		if (spellBook.find(spell->getName()) == spellBook.end()) //retorna spellBook.end() quando nao acha
			spellBook[spell->getName()] = spell->clone();
}

void    SpellBook::forgetSpell(const std::string &spellName) {
    if (spellBook.find(spellName) != spellBook.end()) {
        delete spellBook[spellName]; //frees the memory 
        spellBook.erase(spellBook.find(spellName)); //removes the entry (key-value pair) from the map
    }
}

ASpell  *SpellBook::createSpell(const std::string &spellName) {
    ASpell *tmp = NULL;
    if (spellBook.find(spellName) != spellBook.end()) { 
        tmp = spellBook[spellName];
    }
    return tmp;
}
