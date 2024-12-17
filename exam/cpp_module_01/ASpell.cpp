#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &ref) {
    if (this != &ref)
        *this = ref;
}

ASpell::~ASpell() {}

ASpell & ASpell::operator=(const ASpell &ref) {
    this->name = ref.name;
    this->effects = ref.effects;
    return *this;
}

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {}

std::string ASpell::getName() const {
    return this->name;
}

std::string ASpell::getEffects() const {
    return this->effects;
}

void ASpell::launch(const ATarget &atarget) {
    atarget.getHitBySpell(*this);
}
