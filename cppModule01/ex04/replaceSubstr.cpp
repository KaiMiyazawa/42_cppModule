/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceSubstr.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:32:04 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2024/06/19 16:34:42 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

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
