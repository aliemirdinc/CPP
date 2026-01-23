/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:59:03 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/23 15:39:53 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	try {
		Array<int> numbers(5);
		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 2;

		std::cout << "Numbers size: " << numbers.size() << std::endl;

		Array<int> copy = numbers;
		copy[0] = 42;

		std::cout << "Original[0]: " << numbers[0] << std::endl;
		std::cout << "Original[1]: " << numbers[1] << std::endl;
		std::cout << "Original[2]: " << numbers[2] << std::endl;
		std::cout << "Original[3]: " << numbers[3] << std::endl;
		std::cout << "Original[4]: " << numbers[5] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;

		std::cout << "Testing exception..." << std::endl;
		std::cout << numbers[10] << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		Array<float> fl_nums(3);
		for (unsigned int i = 0; i < fl_nums.size(); i++)
			fl_nums[i] = i * 2.2;
		std::cout << "Numbers size: " << fl_nums.size() << std::endl;

		Array<float> copy2 = fl_nums;
		copy2[0] = 42;

		std::cout << "Original[0]: " << fl_nums[0] << std::endl;
		std::cout << "Original[1]: " << fl_nums[1] << std::endl;
		std::cout << "Original[2]: " << fl_nums[2] << std::endl;
		std::cout << "Copy2[0]: " << copy2[0] << std::endl;

		std::cout << "Testing exception..." << std::endl;
		std::cout << fl_nums[10] << std::endl;
		
		
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	return 0;
}
