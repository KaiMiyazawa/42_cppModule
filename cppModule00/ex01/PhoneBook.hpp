/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:51:27 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/11 14:34:07 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	welcomeMsg(void) const;
		void	explainMsg(void) const;
		void	addContact(void);
		void	printContacts(void) const;
		void	search(void) const;
};

#endif