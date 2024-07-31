/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:35:53 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/07/31 22:14:15 by miyazawa.ka      ###   ########.fr       */
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
	if (s1 == "")
	{
		std::cerr << "Error: s1 is empty." << std::endl;
		return ;
	}

	std::ifstream infile(this->_filenameIn.c_str());
	std::string line;

	if (infile.is_open())
	{
		if (std::getline(infile, line, '\0'))
		{
			std::ofstream outfile(this->_filenameOut.c_str());
			if (line.find(s1) != std::string::npos)
			{
				line = replaceSubstr(line, s1, s2);
			}
			outfile << line;
			outfile.close();
		}
		else
		{
			std::cerr << "Warning: Empty file." << std::endl;
		}
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	infile.close();
	return ;
}

std::string replaceSubstr(std::string &line, std::string s1, std::string s2)
{
	std::string result = "";
	size_t startPos = 0;
	size_t endPos;
	std::string tmp;

	while (true)
	{
		endPos = line.find(s1, startPos);
		if (endPos == std::string::npos)
			break;
		tmp = line.substr(startPos, endPos - startPos);
		result = result + tmp + s2;
		startPos = endPos + s1.length();
	}
	result = result + line.substr(startPos, line.length() - startPos);
	return result;
}
