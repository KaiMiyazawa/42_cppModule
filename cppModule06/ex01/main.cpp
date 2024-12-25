#include "Serializer.hpp"
// #include <cstdint>
#include <stdint.h>

int main()
{
    Data data;
    data.name = "John";
    data.age = 42;
    data.address = "42 Main St.";
    data.email = "sample@gmail.com";

    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Address: " << data.address << std::endl;
    std::cout << "Email: " << data.email << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "Serialized: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Address: " << deserialized->address << std::endl;
    std::cout << "Email: " << deserialized->email << std::endl;
    
    return 0;
}