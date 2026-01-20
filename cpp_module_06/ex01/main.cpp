/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:26:03 by aldinc            #+#    #+#             */
/*   Updated: 2026/01/20 18:34:52 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>


int main(void) {
	Data *d = new Data();
	uintptr_t u = 0;

	d->content = 1;
	d->id = 0;
	std::cout << "original address= " <<  d << std::endl;
	u = Serializer::serialize(d);
	std::cout << "Serialized address= " << u << std::endl;
	d = Serializer::deserialize(u);
	std::cout << "Deserialized address of serialized address (basicly original address)" << d << std::endl;

	delete(d);
}
