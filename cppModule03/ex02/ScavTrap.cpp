#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->_name = copy._name;
    this->_hitPoints = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;

    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode" << std::endl;
}

// ここの解釈よくわからん