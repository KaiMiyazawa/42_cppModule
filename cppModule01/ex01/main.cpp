/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:41 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/07/25 22:54:52 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 42

int main(void){
	std::cout << "Creating many zombies." << std::endl;
	Zombie *zombies = zombieHorde(N, "Zombie");

	if (zombies)
	{
		std::cout << N << " zombies are created." << std::endl;
		for (int i = 0; i < N; i++)
		{
			zombies[i].announce();
		}
	}
	else
	{
		std::cout << "Failed to create zombies." << std::endl;
	}

	delete [] zombies;
	return (0);
}
