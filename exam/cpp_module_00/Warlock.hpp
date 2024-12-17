#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
    private:
        std::string name;
        std::string title;

        Warlock(const Warlock &ref);
        Warlock & operator=(const Warlock &rhs);
        Warlock();

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        const std::string&  getName() const;
        const std::string&  getTitle() const;
        void                setTitle(const std::string &);

        void                introduce() const;
};

#endif
