#pragma once
#include "ASpell.hpp"

class Polymorph : public ASpell {
    public:
        Polymorph();
        ~Polymorph();
        ASpell* clone() const; //<-Para sobrescrever clone vc deve declarar sua assinatura

};
