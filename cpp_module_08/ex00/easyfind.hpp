/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:22:29 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/26 16:15:00 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <list>
# include <stdexcept>
template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end()) {
		throw std::runtime_error("Element not found in container");
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int to_find) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end()) {
		throw std::runtime_error("Element not found in container");
	}
	return it;
}

#endif