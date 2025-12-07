/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:12:16 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/21 18:12:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	void loadData(const std::string& filename);
	float getExchangeRate(const std::string& date) const;
	void processInputFile(const std::string& filename);
	
private:
	std::map<std::string, float> exchangeRates;
	bool isValidDate(const std::string& date) const;
	bool isValidValue(float value) const;
	std::string findClosestDate(const std::string& date) const;
	void parseLine(const std::string& line);
};

std::string read_db(const std::string& filename);

#endif


