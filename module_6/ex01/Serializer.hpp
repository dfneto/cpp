#pragma once

#include <iostream>
#include <stdint.h>  // Required for uintptr_t in C++98

struct Data {
    int id;
    std::string name;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer &ref);
    ~Serializer();
    Serializer &operator=(const Serializer &ref);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

