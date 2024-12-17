#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget {
    public:
        BrickWall();
        ~BrickWall();
        ATarget* clone() const; //<-Para sobrescrever clone vc deve declarar sua assinatura

};
