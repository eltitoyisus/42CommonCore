/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:51:40 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 12:51:40 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

char *replace_file(char *file, char *s1, char *s2)
{
	std::string filename = file;
	std::ifstream origin(filename.c_str());
	if (!origin)
	{
		std::cout << "Error: origin file" << std::endl;
		return 0;
	}
	std::ofstream destiny((filename + ".replace").c_str());
	if (!destiny)
	{
		std::cout << "Error: destiny file" << std::endl;
		return 0;
	}

	std::string content((std::istreambuf_iterator<char>(origin)), std::istreambuf_iterator<char>());
	origin.close();

	std::string str1 = s1;
	std::string str2 = s2;
	size_t pos = 0;
	while ((pos = content.find(str1, pos)) != std::string::npos)
	{
		content.replace(pos, str1.length(), str2);
		pos += str2.length();
	}

	destiny << content;
	destiny.close();
	return 0;
}
