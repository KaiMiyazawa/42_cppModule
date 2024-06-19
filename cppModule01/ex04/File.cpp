/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:35:53 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/19 16:51:21 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filenameIn) : _filenameIn(filenameIn)
{
	this->_filenameOut = filenameIn + ".replace";
}

File::~File()
{
}

void File::replace(std::string s1, std::string s2)
{
	std::ifstream infile(this->_filenameIn);
	std::ofstream outfile(this->_filenameOut);
	std::string line;

	if (infile.is_open())
	{
		if (std::getline(infile, line, '\0'))
		{
			if (line.find(s1) != std::string::npos)
			{
				line = replaceSubstr(line, s1, s2);
			}
			outfile << line;
		}
		else
		{
			std::cerr << "Warning: Empty file." << std::endl;
		}
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	infile.close();
	outfile.close();
	return ;
}