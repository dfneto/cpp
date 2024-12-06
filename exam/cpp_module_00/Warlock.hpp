#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
    private:
        std::string name;
        std::string title;

    public:
        Warlock(const Warlock &src) = delete;
        Warlock(std::string name, std::string title);
        ~Warlock();
        Warlock & operator=(const Warlock &ref) = delete;

        const std::string getName();
        const std::string getTitle();
        void              setTitle(const std::string newTitle)
};

#endif