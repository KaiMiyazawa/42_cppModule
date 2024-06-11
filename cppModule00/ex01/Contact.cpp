/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:48:32 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/10 19:46:45 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const
{
	std::string input = "";
	bool valid = false;
	while (!valid)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (!input.empty() && std::cin.good())
		{
			valid = true;
		}
		else
		{
			std::cin.clear();
			std::cout << "Please enter a valid input." << std::endl;
		}
	}
	return (input);
}

void Contact::init(void)
{
	// 入力バッファを一文字だけクリア
	std::cin.ignore();
	this->_firstName = this->_getInput("Enter the first name: ");
	this->_lastName = this->_getInput("Enter the last name: ");
	this->_nickname = this->_getInput("Enter the nickname: ");
	this->_phoneNumber = this->_getInput("Enter the phone number: ");
	this->_darkestSecret = this->_getInput("Enter the darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::setIndex(int i)
{
	this->_index = i;
}

void	Contact::view(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
	{
		std::cout << std::endl;
		std::cout << "No contact #" << index << " information available." << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "Contact #" << index << std::endl;
	std::cout << "First name:\t" << this->_firstName << std::endl;
	std::cout << "Last name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << this->_darkestSecret << std::endl;
	std::cout << std::endl;
	return ;
}