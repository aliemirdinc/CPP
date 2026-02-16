/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:58 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/16 16:32:37 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl; // Subject output ile uyumlu olması için
		return 1;
	}

	BitcoinExchange btc;
	btc.run(argv[1]);

	return 0;
}