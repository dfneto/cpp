#pragma once

#include <iostream>

class ASpell;

class ATarget {
	protected:
		std::string type;
	
	public:
		ATarget();
		ATarget(const ATarget &);
		ATarget(std::string);
		virtual ~ATarget();
		
		ATarget& operator=(const ATarget &);
		virtual ATarget* clone() const = 0;
		const std::string & getType() const;
		void getHitBySpell(const ASpell &) const;
};

