/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:56:28 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/20 16:31:13 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

void RPN::run(const std::string& expression) {
	std::stack<int> s;

	for (size_t i = 0; i < expression.length(); i++) {
		// Skip whitespace
		if (expression[i] == ' ') continue;

		// Digit (0-9)
		if (isdigit(expression[i])) {
			int num = expression[i] - '0';
			s.push(num);
		}
		// Operator
		else if (expression[i] == '+' || expression[i] == '-' || 
				 expression[i] == '*' || expression[i] == '/') {

			// Need at least two numbers
			if (s.size() < 2) {
				std::cout << "Error" << std::endl;
				return;
			}

			// LIFO order
			int val2 = s.top(); s.pop();
			int val1 = s.top(); s.pop();

			if (expression[i] == '+') s.push(val1 + val2);
			else if (expression[i] == '-') s.push(val1 - val2);
			else if (expression[i] == '*') s.push(val1 * val2);
			else if (expression[i] == '/') {
				if (val2 == 0) {
					std::cout << "Error" << std::endl;
					return;
				}
				s.push(val1 / val2);
			}
		}
		// Invalid character
		else {
			std::cout << "Error" << std::endl;
			return;
		}
	}

	// Verify result
	if (s.size() != 1) {
		std::cout << "Error" << std::endl;
		return;
	}

	std::cout << s.top() << std::endl;
}