/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:36:11 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/19 14:55:36 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	if (this->_weapon.getType() == "")
		std::cout << this->_name << " attacks with no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}
