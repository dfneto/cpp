#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"

class Warlock {
    private:
        Warlock(const Warlock &ref);
        Warlock & operator=(const Warlock &rhs);
        Warlock();
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> spellBook;

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
