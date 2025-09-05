/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:18:52 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 10:11:16 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Testing Animal polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* DOG42 = new Dog();
	const Animal* CAT42 = new Cat();
	
	std::cout << DOG42->getType() << " " << std::endl;
	std::cout << CAT42->getType() << " " << std::endl;
	DOG42->makeSound();
	CAT42->makeSound();
	meta->makeSound();
	
	delete meta;
	delete DOG42;
	delete CAT42;
	
	std::cout << "\n=== Testing WrongAnimal (no polymorphism) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	
	delete wrongMeta;
	delete wrongCat;
	
	std::cout << "\n=== Testing direct object creation ===" << std::endl;
	Dog directDog;
	Cat directCat;
	WrongCat directWrongCat;
	
	std::cout << "Direct dog type: " << directDog.getType() << std::endl;
	directDog.makeSound();
	
	std::cout << "Direct cat type: " << directCat.getType() << std::endl;
	directCat.makeSound();
	
	std::cout << "Direct wrong cat type: " << directWrongCat.getType() << std::endl;
	directWrongCat.makeSound();
	
	return 0;
}
