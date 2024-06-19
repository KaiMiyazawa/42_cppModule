/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:15:58 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/17 01:29:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void) const;
		Zombie *newZombie(std::string name);
		void	randomChump(std::string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif