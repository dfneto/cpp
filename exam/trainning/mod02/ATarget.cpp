#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const ATarget &ref) {
	if (this != &ref)
		*this = ref;
}

ATarget::ATarget(std::string type) : type(type) {}

ATarget::~ATarget() {}
		
ATarget& ATarget::operator=(const ATarget &ref) {
	this->type = ref.type;
	return *this;
}

const std::string & ATarget::getType() const {
	return this->type;
}

void ATarget::getHitBySpell(const ASpell &aspell) const {
	std::cout << this->type << " has been " << aspell.getEffects() << "!" << std::endl; 
}

