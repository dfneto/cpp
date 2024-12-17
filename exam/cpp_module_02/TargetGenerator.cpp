#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & src) {
    if (this != &src)
	    *this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src) {
	targetMap = src.targetMap;
	return (*this);
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target)
        if (targetMap.find(target->getType()) == targetMap.end())
            targetMap[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const & name) {
    if (targetMap.find(name) != targetMap.end()) {
        delete targetMap[name];
        targetMap.erase(targetMap.find(name));
    }
}

ATarget* TargetGenerator::createTarget(std::string const &name) {
    ATarget *tmp = NULL;
    if (targetMap.find(name) != targetMap.end())
        tmp = targetMap[name];
    return tmp;
}

