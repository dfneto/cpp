#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &ref) {
	if (this != &ref)
		*this = ref;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator &ref) {
	(void)ref;
	return *this;
}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (target)
		if (targetBook.find(target->getType()) == targetBook.end())
			targetBook[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &name) {
	if (targetBook.find(name) != targetBook.end()) {
		delete targetBook[name];
		targetBook.erase(targetBook.find(name));
	}
}

ATarget* TargetGenerator::createTarget(const std::string &name) {
	ATarget *target = NULL;
	if (targetBook.find(name) != targetBook.end()) {
		target = targetBook[name];
	}
	return target;
}


