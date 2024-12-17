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
        spellBook.learnSpell(spell);
}

void    Warlock::forgetSpell(std::string spellName) {
    spellBook.forgetSpell(spellName);
}

void    Warlock::launchSpell(std::string spellName, ATarget &target) {
    ASpell  *spell = spellBook.createSpell(spellName);
    if (spell)
        spell->launch(target);
}

