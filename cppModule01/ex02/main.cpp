/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:41 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/19 14:16:53 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;
	std::string brain2 = brain;

	std::cout << "the memory address of ... =====" << std::endl;
	std::cout << "String: " << &brain << std::endl;
	std::cout << "Pointer: " << brainPtr << std::endl;
	std::cout << "Reference: " << &brainRef << std::endl;

	std::cout << "the value of ... ==============" << std::endl;
	std::cout << "String: " << brain << std::endl;
	std::cout << "Pointer: " << *brainPtr << std::endl;
	std::cout << "Reference: " << brainRef << std::endl;
	return (0);
}
