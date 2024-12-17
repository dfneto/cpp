#ifndef WARLOCK_HPP
#define WARLOCK_HPP

// #include <iostream>
// #include <string>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
    private:
        Warlock();
        Warlock(const Warlock &ref);
        Warlock & operator=(const Warlock &rhs);
        std::string name;
        std::string title;
        SpellBook spellBook; //SpellBook class must have a default constructor or I use a pointer

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        const std::string&  getName() const;
        const std::string&  getTitle() const;
        void                setTitle(const std::string &newTitle);

        void                introduce() const;

        void                learnSpell(ASpell *);
        void                forgetSpell(std::string);
        void                launchSpell(std::string, ATarget &);
};

#endif
