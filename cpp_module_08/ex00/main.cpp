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
#include <vector>

int main() {

	std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    
    try {
        std::cout << "Vector test: " << *easyfind(v, 10) << " found." << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(100);
    l.push_back(200);

    try {
        std::cout << "List test: " << *easyfind(l, 200) << " found." << std::endl;
        easyfind(l, 999);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}