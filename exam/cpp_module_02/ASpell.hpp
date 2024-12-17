#ifndef ASPELL_HPP
#define ASPELL_HPP

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
        virtual ~ASpell(); //<-Lembrar que eh virtual

        ASpell & operator=(const ASpell &);

        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell *clone() const = 0;
        void launch(const ATarget &); //<- Lembrar de ser const

};

#endif