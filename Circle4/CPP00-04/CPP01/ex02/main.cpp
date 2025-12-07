/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:52:43 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/07 22:52:43 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *pBrain = &brain;
	std::string &rBrain = brain;

	std::cout << std::endl;
	std::cout << "memory address of string: " << &brain << std::endl;
	std::cout << "memory address of stringPTR: " << pBrain << std::endl;
	std::cout << "memory address of stringREF: " << &rBrain << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "memory address of string: " << brain << std::endl;
	std::cout << "memory address of stringPTR: " << *pBrain << std::endl;
	std::cout << "memory address of stringREF: " << rBrain << std::endl;
	std::cout << std::endl;
}
