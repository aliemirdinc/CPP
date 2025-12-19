/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:57:09 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/19 19:07:34 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONV
# define SCALAR_CONV

# include <string>
# include <iostream>
# include <limits>
# include <cstdlib>  

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &assign);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

#endif