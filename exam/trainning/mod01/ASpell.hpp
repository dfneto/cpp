#pragma once

#include <string>

class ATarget;

class ASpell {
	protected:
		std::string name;
		std::string effects;
	
	public:
		ASpell();
		ASpell(const ASpell &);
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();
		
		ASpell& operator=(const ASpell &);
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget &);
};

