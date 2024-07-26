
#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
    FragTrap fragTrap1("jim");
    FragTrap fragTrap2("bob");

    fragTrap1.attack(fragTrap2.getName());
    fragTrap1.takeDamage(fragTrap1.getAttackDamage());
    fragTrap1.beRepaired(5);
    fragTrap1.highFivesGuys();
}

// {
//     ScavTrap scavTrap1("jim");
//     ScavTrap scavTrap2("bob");

//     scavTrap1.attack(scavTrap2.getName());
//     scavTrap1.takeDamage(scavTrap1.getAttackDamage());
//     scavTrap1.beRepaired(5);
//     scavTrap1.guardGate();
// }
    // ClapTrap clapTrap1("ClapTrap1");
    // ClapTrap clapTrap2("ClapTrap2");

    // clapTrap1.setAttackDamage(10);
    // clapTrap2.setAttackDamage(20);
    // clapTrap1.attack(clapTrap2.getName());
    // clapTrap1.takeDamage(clapTrap2.getAttackDamage());
    // clapTrap1.beRepaired(5);
    // return 0;