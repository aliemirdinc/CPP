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

#ifndef EASYFIND
# define EASYFIND
# include <iostream>
# include <vector>
# include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif