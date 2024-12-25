#include "B.hpp"

B::B() {
    std::cout << "B constructor" << std::endl;
}

B::~B() {
    std::cout << "B destructor" << std::endl;
}

B::B(const B &copy) {
    *this = copy;
}

B &B::operator=(const B &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}