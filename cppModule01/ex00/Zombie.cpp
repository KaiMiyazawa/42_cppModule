/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:23:07 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/17 01:34:52 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": " << " BraiiiiiiinnnzzzZ..." << std::endl;
}