/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:59:06 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/23 14:19:20 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
	T* _elements;
	unsigned int    _arraySize;

public:
	Array() : _elements(NULL), _arraySize(0) {}

	Array(unsigned int n) : _arraySize(n) {
		_elements = new T[n]();
	}

	Array(const Array& other) : _elements(NULL), _arraySize(0) {
		*this = other;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (this->_elements)
				delete[] this->_elements;
			this->_arraySize = other._arraySize;
			this->_elements = new T[this->_arraySize];
			for (unsigned int i = 0; i < this->_arraySize; i++) {
				this->_elements[i] = other._elements[i];
			}
		}
		return *this;
	}

	~Array() {
		if (this->_elements)
			delete[] this->_elements;
	}

	T& operator[](unsigned int index) {
		if (index >= _arraySize || _elements == NULL)
			throw std::out_of_range("Index is out of bounds!");
		return _elements[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _arraySize || _elements == NULL)
			throw std::out_of_range("Index is out of bounds!");
		return _elements[index];
	}

	unsigned int size() const {
		return _arraySize;
	}
};

#endif