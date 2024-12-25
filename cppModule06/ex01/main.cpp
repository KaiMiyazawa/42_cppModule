#include "Serializer.hpp"
#include <cstdint>

int main()
{
    Data data;
    data.name = "John";
    data.age = 42;
    data.address = "42 Main St.";
    data.email = "sample@gmail.com";

    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "Serialized: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Address: " << deserialized->address << std::endl;
    std::cout << "Email: " << deserialized->email << std::endl;
    
    return 0;
}