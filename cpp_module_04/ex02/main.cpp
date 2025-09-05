/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:18:52 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 11:18:46 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::cout << "=== Basic test from subject ===" << std::endl;
	
	// Animal* meta = new Animal()
	// This would be an error - cannot instantiate abstract class
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	std::cout << "\n=== Array test (half Dogs, half Cats) ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	// Fill array - half Dogs, half Cats
	for (int idx = 0; idx < arraySize; idx++) {
		if (idx < arraySize / 2) {
			animals[idx] = new Dog();
			std::cout << "Created Dog at index " << idx << std::endl;
		} else {
			animals[idx] = new Cat();
			std::cout << "Created Cat at index " << idx << std::endl;
		}
	}
	
	std::cout << "\n=== Testing sounds ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
		animals[idx]->makeSound();
	}
	
	std::cout << "\n=== Cleaning up array ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << "Deleting animal at index " << idx << std::endl;
		delete animals[idx];
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog originalDog;
	originalDog.setBrainIdea(0, "I am the original dog");
	originalDog.setBrainIdea(1, "I love bones");
	
	std::cout << "\nCopying dog..." << std::endl;
	Dog copiedDog = originalDog; // Copy constructor
	
	std::cout << "Original dog idea 0: " << originalDog.getBrainIdea(0) << std::endl;
	std::cout << "Copied dog idea 0: " << copiedDog.getBrainIdea(0) << std::endl;
	
	// Change original to test deep copy
	originalDog.setBrainIdea(0, "I am the MODIFIED original dog");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original dog idea 0: " << originalDog.getBrainIdea(0) << std::endl;
	std::cout << "Copied dog idea 0 (should be unchanged): " << copiedDog.getBrainIdea(0) << std::endl;
	
	Cat originalCat;
	originalCat.setBrainIdea(0, "I am the original cat");
	originalCat.setBrainIdea(1, "I love fish");
	
	std::cout << "\nCopying cat..." << std::endl;
	Cat copiedCat = originalCat; // Copy constructor
	
	std::cout << "\nTesting assignment operator..." << std::endl;
	Dog anotherDog;
	anotherDog.setBrainIdea(0, "I am another dog");
	anotherDog = originalDog; // Assignment operator
	std::cout << "After assignment, another dog idea 0: " << anotherDog.getBrainIdea(0) << std::endl;
	
	std::cout << "\n=== Program ending ===" << std::endl;
	return 0;
}
