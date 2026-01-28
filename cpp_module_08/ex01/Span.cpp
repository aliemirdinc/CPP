/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:13:16 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/27 13:13:17 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
	_numbers.reserve(n);
}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &assign) {
	if (this != &assign) {
		this->_n = assign._n;
		this->_numbers = assign._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _n)
        throw std::runtime_error("Span is full!");
    _numbers.push_back(number);
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Need at least two numbers for a span!");
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	return (tmp.back() - tmp.front());
}

int Span::shortestSpan() {
	int min;
	if (_numbers.size() < 2)
		throw std::runtime_error("too few numbers inside the container");

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	min = (tmp[1] - tmp[0]);

	for (size_t i = 0; i < tmp.size() - 1; i++) {
		int diff = tmp[i + 1] - tmp[i];
		if (diff < min)
			min = diff;
	}
	return (min);
}
