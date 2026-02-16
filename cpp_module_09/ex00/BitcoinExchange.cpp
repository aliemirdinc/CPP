/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:47 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/16 16:32:17 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// --- Orthodox Canonical Form ---
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

// String'in başındaki ve sonundaki boşlukları temizler
std::string BitcoinExchange::_trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (std::string::npos == first) return str;
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

// Tarih formatını (YYYY-MM-DD) ve mantığını kontrol eder
bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) return false;

	// Basit ay gün kontrolü (Layığıyla yapmak için Şubat kontrolü eklenebilir)
	if (day > 31) return false;
	if (month == 2 && day > 29) return false; // Basit kontrol
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

	return true;
}

// Değerin sayısal olup olmadığını, negatifliğini ve 1000 sınırını kontrol eder
bool BitcoinExchange::_isValidValue(const std::string& valueStr, float &value) {
	char* end;
	value = std::strtod(valueStr.c_str(), &end);

	// Eğer string tamamen sayıya çevrilemediyse (örn: "12a")
	if (*end != '\0' && end != valueStr.c_str() + valueStr.length()) return false;
	
	// C++98'de strtod boş string için 0.0 dönebilir, kontrol edelim
	if (valueStr.empty()) return false;

	return true;
}

// --- Core Logic ---

void BitcoinExchange::_loadDatabase() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		// Opsiyonel: Burada exit atabilir veya boş map ile devam edip run'da hata verebiliriz.
		// Konu gereği exception atmak veya hata basmak uygundur.
		return;
	}

	std::string line;
	std::getline(file, line); // İlk satırı (Header) atla

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
	std::getline(file, line); // Input dosyasının header'ını atla ("date | value")

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
		if (!_isValidValue(valueStr, value)) { // Sayı formatı bozuksa
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

		// --- ALGORİTMA: En Yakın Tarihi Bulma ---
		std::map<std::string, float>::const_iterator it = _database.upper_bound(date);

		if (it == _database.begin()) {
			std::cout << "Error: no data for this date or earlier." << std::endl;
		} else {
			--it; // upper_bound bir sonrakini verir, bir geri giderek "eşit veya küçük en büyük" tarihi buluyoruz[cite: 168].
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	file.close();
}