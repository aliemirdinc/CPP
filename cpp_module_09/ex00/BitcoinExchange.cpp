/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:47 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/20 15:57:28 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	_loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// --- Helper Functions ---
// Trim whitespace
std::string BitcoinExchange::_trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\r\n");
	if (std::string::npos == first) return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, (last - first + 1));
}

// Validate date
bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1) return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (month == 2 && isLeapYear)
		daysInMonth[1] = 29;
	
	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

// Validate numeric value
bool BitcoinExchange::_isValidValue(const std::string& valueStr, float &value) {
	char* end;
	value = std::strtod(valueStr.c_str(), &end);

	// Verify fully numeric
	if (*end != '\0' && end != valueStr.c_str() + valueStr.length()) return false;
	
	// Check empty string
	if (valueStr.empty()) return false;

	return true;
}

void BitcoinExchange::_loadDatabase() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;

	// Skip header
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t delim = line.find(',');
		if (delim == std::string::npos) continue;

		std::string date = _trim(line.substr(0, delim));
		std::string rateStr = _trim(line.substr(delim + 1));
		
		_database[date] = std::atof(rateStr.c_str());
	}
	file.close();
}

void BitcoinExchange::run(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	// Skip header
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t delim = line.find('|');
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = _trim(line.substr(0, delim));
		std::string valueStr = _trim(line.substr(delim + 1));

		if (!_isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value;
		if (!_isValidValue(valueStr, value)) {
			 std::cout << "Error: bad input => " << valueStr << std::endl;
			 continue;
		}
		
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		// Find closest date
		std::map<std::string, float>::const_iterator it = _database.upper_bound(date);

		if (it == _database.begin()) {
			std::cout << "Error: no data for this date or earlier." << std::endl;
		} else {
			--it;
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	file.close();
}
