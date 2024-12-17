#pragma once

#include <map>
#include "ASpell.hpp"

class SpellBook {
    private:
        SpellBook(const SpellBook &ref);
        SpellBook & operator=(const SpellBook &rhs);
        std::map<std::string, ASpell *> spellBook;
        
    public:
        SpellBook();
        ~SpellBook();

        void                learnSpell(ASpell *);
        void                forgetSpell(const std::string &);
        ASpell*             createSpell(const std::string &);
};
