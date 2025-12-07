/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:12:17 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/21 18:12:17 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string read_db(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return "";
	}

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	return "";
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		exchangeRates = other.exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}
		
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;
		}
		
		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);
		
		float rate;
		std::istringstream iss(rateStr);
		if (iss >> rate) {
			exchangeRates[date] = rate;
		}
	}
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
	if (it != exchangeRates.end()) {
		return it->second;
	}
	
	std::string closestDate = findClosestDate(date);
	if (!closestDate.empty()) {
		it = exchangeRates.find(closestDate);
		if (it != exchangeRates.end()) {
			return it->second;
		}
	}
	
	return -1.0f;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) continue;
		if (date[i] < '0' || date[i] > '9') return false;
	}
	
	int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	int month = (date[5] - '0') * 10 + (date[6] - '0');
	int day = (date[8] - '0') * 10 + (date[9] - '0');
	
	if (year < 2009 || year > 2025) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28)) return false;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	}
	
	return true;
}

bool BitcoinExchange::isValidValue(float value) const {
	return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
	std::string closest = "";
	for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
		if (it->first <= date) {
			closest = it->first;
		} else {
			break;
		}
	}
	return closest;
}

void BitcoinExchange::parseLine(const std::string& line) {
	size_t pipePos = line.find(" | ");
	if (pipePos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	
	std::string date = line.substr(0, pipePos);
	std::string valueStr = line.substr(pipePos + 3);
	
	if (!isValidDate(date)) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	
	float value;
	std::istringstream iss(valueStr);
	if (!(iss >> value)) {
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return;
	}
	
	std::string remaining;
	iss >> remaining;
	if (!remaining.empty()) {
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return;
	}
	
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if (!isValidValue(value)) {
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}
	
	float rate = getExchangeRate(date);
	if (rate < 0) {
		std::cerr << "Error: no data available for date " << date << std::endl;
		return;
	}
	
	float result = value * rate;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}
		
		if (firstLine) {
			firstLine = false;
			continue;
		}
		
		parseLine(line);
	}
}
