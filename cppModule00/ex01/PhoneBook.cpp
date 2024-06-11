/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:48:37 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/11 14:34:07 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcomeMsg(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to the phone book!" << std::endl;
}

void PhoneBook::explainMsg(void) const
{
	std::cout << std::endl;
	std::cout << "========== Commands: ==========" << std::endl;
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
	std::cout << std::endl;
	std::cout << "================= CONTACTS =================" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		this->_contacts[i].displayFew(i);
	}
	std::cout << std::endl;
}

void	PhoneBook::search(void) const
{
	//何番の電話番号を表示するのかの入力うけ
	int input = -1;
	bool	valid = false;
	while (!valid)
	{
		std::cout << "Enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input <= 7))
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
	//番号に対応する電話帳の情報をput
	this->_contacts[input].displayAll(input);
}