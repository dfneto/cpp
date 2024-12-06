#include "Warlock.hpp"

const std::string Warlock::getName() {
    return this->name;
}

const std::string Warlock::getTitle() {
    return this->title;
}

void Warlock::setTitle(const std::string newTitle) {
    this->title = newTitle;
}