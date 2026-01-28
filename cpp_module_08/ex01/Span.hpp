/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:13:18 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/27 13:25:33 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>

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
		void shortestSpan(Span numbers);
		void longestSpan(Span numbers);

};

#endif