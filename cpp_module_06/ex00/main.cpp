/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:08:32 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/19 19:08:32 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    } else {
        std::cout << "Error: Bad arguments." << std::endl;
    }
    return 0;
}