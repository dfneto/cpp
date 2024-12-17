#ifndef dummy
#define dummy

#include "ATarget.hpp"

class Dummy : public ATarget {
    public:
        Dummy();
        ~Dummy();
        ATarget* clone() const; //<-Para sobrescrever clone vc deve declarar sua assinatura

};

#endif
