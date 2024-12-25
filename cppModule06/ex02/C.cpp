#include "C.hpp"

C::C() {
    std::cout << "C constructor" << std::endl;
}

C::~C() {
    std::cout << "C destructor" << std::endl;
}

C::C(const C &copy) {
    *this = copy;
}

C &C::operator=(const C &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}