
#pragma once

#include <map> 
#include <iostream>
#include "ATarget.hpp"

class TargetGenerator {
	private:
		TargetGenerator(const TargetGenerator &);
		TargetGenerator & operator=(const TargetGenerator &);
		std::map<std::string, ATarget *>targetBook;

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *);
		void forgetTargetType(const std::string &);
		ATarget* createTarget(const std::string &);
};
