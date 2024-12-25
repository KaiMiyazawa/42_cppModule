#include "A.hpp"

A::A() {
    std::cout << "A constructor" << std::endl;
}

A::~A() {
    std::cout << "A destructor" << std::endl;
}

A::A(const A &copy) {
    *this = copy;
}

A &A::operator=(const A &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}