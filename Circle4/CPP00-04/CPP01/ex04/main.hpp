/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:51:37 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 12:51:37 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

// replace has to take the <filename> <string 1> <string 2>

// create <filename.replace> and change <s1> occurences for <s2>

class Replace
{
	public:
		Replace();
		~Replace();
		char *replace_file(char *file, char *s1, char *s2);

	private:
	
};

char *replace_file(char *file, char *s1, char *s2);
