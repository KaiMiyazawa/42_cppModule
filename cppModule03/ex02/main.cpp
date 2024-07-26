
#include <iostream>

#include "ScavTrap.hpp"


int main(void)
{
    ScavTrap scavTrap1("jim");
    ScavTrap scavTrap2("bob");

    scavTrap1.attack(scavTrap2.getName());
    scavTrap1.takeDamage(scavTrap1.getAttackDamage());
    scavTrap1.beRepaired(5);
    scavTrap1.guardGate();
}
    // ClapTrap clapTrap1("ClapTrap1");
    // ClapTrap clapTrap2("ClapTrap2");

    // clapTrap1.setAttackDamage(10);
    // clapTrap2.setAttackDamage(20);
    // clapTrap1.attack(clapTrap2.getName());
    // clapTrap1.takeDamage(clapTrap2.getAttackDamage());
    // clapTrap1.beRepaired(5);
    // return 0;