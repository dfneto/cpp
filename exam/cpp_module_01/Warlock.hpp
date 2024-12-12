#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
    private:
        Warlock(const Warlock &ref);
        Warlock & operator=(const Warlock &rhs);
        Warlock();
        std::string name;
        std::string title;

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        const std::string&  getName() const;
        const std::string&  getTitle() const;
        void                setTitle(const std::string &newTitle);

        void                introduce() const;
};

#endif
