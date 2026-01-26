/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme1.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:45:53 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/26 16:09:42 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec1;
	std::vector<int> vec2(12, 9);
	std::vector<size_t> vec3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "vec3: ";
	for (int i : vec3)
		std::cout << i << " ";
	std::cout << std::endl;

	//-------------------------------------------------------

	vec3.push_back(2);
	vec3.insert(vec3.begin() + 1, 78);

	for (int i : vec3){
		std::cout << i << " ";
	}
	std::cout << std::endl;
	try
	{
		for (size_t i = 0; i < vec3.size() + 1; i++) {
			std::cout << i << "th index = " << vec3.at(i);
			std::cout << std::endl;
		}
	}
	//try ok, learn catch mechanism	
	catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	
	//-------------------------------------------------------

	
	std::cout << "3th index = " << vec2[3] << std::endl;
	std::cout << "3th index changed to = ";
	vec2[3] = 12; 
	std::cout << vec2[3] << std::endl;
	for (int i : vec2){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//-------------------------------------------------------

	std::cout << std::endl;
	std::vector<char> vec4{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'c', 'h'};
	auto it = std::find(vec4.begin(), vec4.end(), 'c');
	std::cout << &it << std::endl;

	auto rit = std::find(vec4.rbegin(), vec4.rend(), 'c');
	std::cout << &rit << std::endl;

	for (int i : vec4) {
		std::cout << static_cast<char>(i) << " ";
	}

	if (rit != vec4.rend()) {
		vec4.erase(std::next(rit).base());
	}

	std::cout << std::endl;
	//vec4.erase(find(vec4.begin(), vec4.end(), 'd'));
	for (int i : vec4)
	std::cout << static_cast<char>(i) << " ";
	std::cout << std::endl;
}
