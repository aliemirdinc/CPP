/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 04:37:02 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/23 16:33:23 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename Type, typename Function>
void iter(Type *array, const size_t length, Function funct) {
	if (array == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		funct(array[i]);
}

template <typename Type>
void printElement(Type &element) {
	std::cout << element << " ";
}

template  < typename Type>
void printElementConst(const Type &printElement) {
	std::cout << printElement << " ";
}

#endif