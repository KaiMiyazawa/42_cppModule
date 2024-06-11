/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:47:58 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/11 14:37:44 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <limits>

int main(void)
{
	PhoneBook book;
	std::string input = "";
	book.welcomeMsg();
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			book.printContacts();
			book.search();
		}
		else
			book.explainMsg();
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return 0;
}
