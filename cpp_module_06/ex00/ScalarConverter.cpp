/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:12:48 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/19 17:12:48 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign) { (void)assign; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string &literal) {
    return (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convert(const std::string &literal) {
	char    c = 0;
	int     i = 0;
	float   f = 0.0f;
	double  d = 0.0;
	
	bool is_char = false;
	bool is_int = false;
	bool is_float = false;
	bool is_double = false;
	bool impossible = false;

	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0])) {
		c = literal[0];
		is_char = true;
	}
	else {
		char *endPtr;
		d = std::strtod(literal.c_str(), &endPtr);

		if (*endPtr == 0) {
			if (literal.find('.') != std::string::npos)
				is_double = true;
			else
				is_int = true;
		}
		else if (*endPtr == 'f' && *(endPtr + 1) == 0) {
			f = std::strtof(literal.c_str(), &endPtr);
			is_float = true;
		}
		else {
			impossible = true;
		}
	}
	
	if (impossible) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (is_char) {
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (is_int) {
		i = static_cast<int>(d);
		c = static_cast<char>(i);
		f = static_cast<float>(d);
	}
	else if (is_float) {
		d = static_cast<double>(f);
		i = static_cast<int>(f);
		c = static_cast<char>(f);
	}
	else if (is_double) {
		f = static_cast<float>(d);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
	}
	
	std::cout << "char: ";
	if (isPseudoLiteral(literal) || d < 0 || d > 127 || std::isnan(d)) {
		std::cout << "impossible";
	} else if (!std::isprint(static_cast<unsigned char>(c))) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'" << c << "'";
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if (isPseudoLiteral(literal) || d > INT_MAX || d < INT_MIN || std::isnan(d)) {
		std::cout << "impossible";
	} else {
		std::cout << i;
	}
	std::cout << std::endl;

	std::cout << "float: ";
	if (is_char)
		std::cout << f << ".0f";
	else {
		std::cout << f;
		if (!isPseudoLiteral(literal) && (f - static_cast<int>(f) == 0))
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (is_char)
		std::cout << d << ".0";
	else {
		std::cout << d;
		if (!isPseudoLiteral(literal) && (d - static_cast<int>(d) == 0))
			std::cout << ".0";
	}
	std::cout << std::endl;
}
