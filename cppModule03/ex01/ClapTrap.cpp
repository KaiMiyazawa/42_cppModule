
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << "ClapTrap " << _name << " is created with copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        if (_hitPoints < amount)
            _hitPoints = 0;
        else
            this->_hitPoints -= amount;
        std::cout << "Remaining hit points: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "Remaining hit points: " << _hitPoints << std::endl;
    }
}

std::string ClapTrap::getName()
{
    return _name;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    _attackDamage = attackDamage;
    std::cout << "ClapTrap " << _name << " attack damage is set to " << _attackDamage << std::endl;
}

unsigned int ClapTrap::getAttackDamage()
{
    return _attackDamage;
}

