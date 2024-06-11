/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:51:27 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/10 19:39:33 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_readInput(void) const;
	public:
		PhoneBook();
		~PhoneBook();
		void	welcome(void) const;
		void	describe(void) const;
		void	addContact(void);
		void	printContacts(void) const;
		void	search(void) const;
};

#endif