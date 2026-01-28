/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:13:18 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/28 18:49:21 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _numbers;
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &assign);
		~Span();

		void addNumber(int number);
		template <typename T>
		void addNumber(T begin, T end) {
			if (_numbers.size() + std::distance(begin, end) > _n)
				throw std::runtime_error("Span limit exceeded!");
			_numbers.insert(_numbers.end(), begin, end);
		}
		int shortestSpan();
		int longestSpan();

};

#endif