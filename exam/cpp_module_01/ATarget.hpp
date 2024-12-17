#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget {

    protected:
        std::string type;
    
    public:
        ATarget();
        ATarget(std::string);
        ATarget(const ATarget &);
        virtual ~ATarget(); //<- Lembrar que eh virtual

        ATarget & operator=(const ATarget &);

        const std::string & getType() const;
        virtual ATarget * clone() const = 0;
        void getHitBySpell(const ASpell &) const; //<- Lembrar que eh const
};

#endif