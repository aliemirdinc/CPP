/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:56:28 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/16 19:01:07 by aldinc           ###   ########.fr       */
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
		// skip first empytinesses
		if (expression[i] == ' ') continue;

		// is it between 0 - 9
		if (isdigit(expression[i])) {
			int num = expression[i] - '0'; // cast char to int
			s.push(num);
		}
		// is it an operator
		else if (expression[i] == '+' || expression[i] == '-' || 
				 expression[i] == '*' || expression[i] == '/') {
			
			// we need at least two number
			if (s.size() < 2) {
				std::cout << "Error" << std::endl;
				return;
			}

			// stack works with LIFO
			int val2 = s.top(); s.pop();
			int val1 = s.top(); s.pop();

			if (expression[i] == '+') s.push(val1 + val2);
			else if (expression[i] == '-') s.push(val1 - val2);
			else if (expression[i] == '*') s.push(val1 * val2);
			else if (expression[i] == '/') {
				if (val2 == 0) {
					std::cout << "Error" << std::endl; // div to zero error
					return;
				}
				s.push(val1 / val2);
			}
		}
		// invalid character
		else {
			std::cout << "Error" << std::endl;
			return;
		}
	}

	// after all iterations there shouldnt be left any values
	if (s.size() != 1) {
		std::cout << "Error" << std::endl;
		return;
	}

	std::cout << s.top() << std::endl;
}