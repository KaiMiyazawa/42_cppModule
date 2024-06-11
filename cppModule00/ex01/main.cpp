/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:47:58 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/10 19:39:50 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <limits>

int main(void)
{
	PhoneBook book;
	std::string input = "";
	book.welcome();
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
			book.describe();
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return 0;
}

