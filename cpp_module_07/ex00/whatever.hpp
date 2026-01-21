/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 03:23:04 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/21 03:41:00 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void swap(T & a, T & b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b ? a : b);
}

template <typename T>
T const & max(T const & a, T const & b) {
	return (a > b ? a : b);
}

#endif