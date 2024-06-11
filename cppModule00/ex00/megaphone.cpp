/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:16:51 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/05/11 17:16:51 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string ToUpper(std::string s)
{
	for (int i = 0; i < int(s.length()); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << ToUpper(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
