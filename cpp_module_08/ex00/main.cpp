/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:21:57 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/26 13:24:40 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Bulundu: " << *it << std::endl;

		easyfind(v, 42);
	}

	catch (const std::exception& e) {
		std::cerr << "Hata: " << e.what() << std::endl;
	}

	return (0);
}