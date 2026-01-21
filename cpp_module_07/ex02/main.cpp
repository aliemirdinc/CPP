/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:59:03 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/21 09:43:30 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include "Array.hpp"
#include <iostream>

int main() {
	try {
		Array<int> numbers(5);
		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 2;

		std::cout << "Numbers size: " << numbers.size() << std::endl;
		
		Array<int> copy = numbers;
		copy[0] = 42;
		
		std::cout << "Original[0]: " << numbers[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;

		std::cout << "Testing exception..." << std::endl;
		std::cout << numbers[10] << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	return 0;
}