/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 04:37:02 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/23 11:02:03 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F funct) {
	if (array == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		funct(array[i]);
}

template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

template  < typename T>
void printElementConst(const T &printElement) {
	std::cout << printElement << " ";
}

#endif