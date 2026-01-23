/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 07:13:52 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/23 11:59:10 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(int);

	std::cout << "Integer Array: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::string strArray[] = {"42", "Istanbul", "Campus", "Piscine"};
	size_t strLen = sizeof(strArray) / sizeof(std::string);

	std::cout << "String Array: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	const int constArray[] = {10, 20, 30};
	size_t constLen = 3;

	std::cout << "Const Array: ";
	::iter(constArray, constLen, printElementConst<int>);
	std::cout << std::endl;

	float float_arr[] = {1.2, 2.4, 12.32, 89.16};
	size_t float_len = sizeof(float_arr) / sizeof(float);
	std::cout << "Float Array: ";
	::iter(float_arr, float_len, printElement<float>);
	std::cout << std::endl;

	return 0;
}
