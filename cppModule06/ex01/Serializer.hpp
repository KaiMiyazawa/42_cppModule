#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
// #include <cstdint>
#include <stdint.h>

struct Data
{
    std::string name;
    int age;
    std::string address;
    std::string email;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &src);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP