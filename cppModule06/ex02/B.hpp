#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
public:
    B();
    virtual ~B();
    B(const B &copy);
    B &operator=(const B &copy);
};

#endif // B_HPP