/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:14:08 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/27 13:14:09 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;

	// std::vector<int> numbers;
    // for (int i = 0; i < 10000; i++)
    //     numbers.push_back(i);

    // Span sp2 = Span(10000);
    // try {
    //     sp2.addNumber(numbers.begin(), numbers.end());
        
    //     std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    //     std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }


	// Span sp = Span(9);

	// try
	// {
	// 	sp.addNumber(1);
	// 	sp.addNumber(5);
	// 	sp.addNumber(98);
	// 	sp.addNumber(7);
	// 	sp.addNumber(14);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	
}