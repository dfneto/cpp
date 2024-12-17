#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock() {}

Warlock::Warlock(const Warlock &ref) {
    *this = ref;
}

Warlock &Warlock::operator=(const Warlock &ref) {
    this->name = ref.name;
    this->title = ref.title;
    return *this;
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

const std::string& Warlock::getName() const {
    return this->name;
}

const std::string& Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(const std::string& newTitle) {
    this->title = newTitle;
}


void    Warlock::learnSpell(ASpell *spell) {
    if (spell)
		if (spellBook.find(spell->getName()) == spellBook.end()) //retorna spellBook.end() quando nao acha
			spellBook[spell->getName()] = spell->clone();
}

void    Warlock::forgetSpell(std::string spellName) {
    if (spellBook.find(spellName) != spellBook.end()) {
        delete spellBook[spellName]; //frees the memory 
        spellBook.erase(spellBook.find(spellName)); //removes the entry (key-value pair) from the map
    }
}

void    Warlock::launchSpell(std::string spellName, ATarget &target) {
    if (spellBook.find(spellName) != spellBook.end())
        spellBook[spellName]->launch(target);
}

