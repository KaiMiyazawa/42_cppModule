/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:41 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/07/25 22:52:38 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main(void){
	std::string name;
	name = "Zombie";

	std::cout << "Zombie on the STACK." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie zombi_stack(name);
	zombi_stack.announce();

	name = "Zombie";

	std::cout << "Zombie on the HEAP." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie *zombi_heap = newZombie(name);
	zombi_heap->announce();
	delete zombi_heap;

	randomChump("zombie_random");
	return (0);
}
