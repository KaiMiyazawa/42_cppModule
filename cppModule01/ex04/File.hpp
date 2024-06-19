/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:33:02 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/19 16:35:26 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string replaceSubstr(std::string &line, std::string s1, std::string s2);

class File
{
	private:
		std::string _filenameIn;
		std::string _filenameOut;
	public:
		File(std::string filename);
		~File();
		void replace(std::string s1, std::string s2);
};

#endif