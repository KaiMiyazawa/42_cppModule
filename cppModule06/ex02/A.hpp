#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
public:
    A();
    virtual ~A();
    A(const A &copy);
    A &operator=(const A &copy);
};

#endif // A_HPP