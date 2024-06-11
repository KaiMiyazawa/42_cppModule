/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:48:37 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/10 19:40:06 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcome(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to the phone book!" << std::endl;
}

void PhoneBook::describe(void) const
{
	std::cout << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "ADD\t: Add a new contact" << std::endl;
	std::cout << "SEARCH\t: Search for a contact" << std::endl;
	std::cout << "EXIT\t: Exit the phone book" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact(void)
{
	static int i;
	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const
{
	std::cout << "CONTACTS" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		this->_contacts[i].view(i);
	}
	std::cout << std::endl;
}


int		PhoneBook::_readInput() const
{
	int		input = -1;
	bool	valid = false;
	while (!valid)
	{
		std::cout << "Enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input <= 8))
		{
			valid = true;
		}
		else
		{
			// 入力バッファのフラグをクリアする
			std::cin.clear();
			// 入力バッファを改行までクリアする
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again." << std::endl;
		}
	}
	return (input);
}

void	PhoneBook::search(void) const
{
	int i;
	i = this->_readInput();
	this->_contacts[i].display(i);
}