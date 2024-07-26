
#include <iostream>

#include "ClapTrap.hpp"


int main(void)
{
    ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2("ClapTrap2");

    clapTrap1.setAttackDamage(10);
    clapTrap2.setAttackDamage(20);
    clapTrap1.attack(clapTrap2.getName());
    clapTrap1.takeDamage(clapTrap1.getAttackDamage());
    clapTrap1.beRepaired(5);
    return 0;
}