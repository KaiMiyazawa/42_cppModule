/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:22:02 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/11 14:32:26 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;

		std::string	_printTenChar(std::string str) const;
		std::string	_getInput(std::string str) const;

	public:
		Contact();
		~Contact();
		void	init(void);
		void	displayFew(int index) const;
		void	displayAll(int index) const;
		void	setIndex(int i);
};

#endif