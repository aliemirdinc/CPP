/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:18:44 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 10:59:40 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    DogBrain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    DogBrain = new Brain(*(other.DogBrain)); // Deep copy
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete DogBrain; // Eski brain'i sil
        DogBrain = new Brain(*(other.DogBrain)); // Yeni brain oluştur (deep copy)
    }
    return *this;
}

Dog::~Dog() {
    delete DogBrain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string& idea) {
    if (DogBrain) {
        DogBrain->setIdea(index, idea);
    }
}

std::string Dog::getBrainIdea(int index) const {
    if (DogBrain) {
        return DogBrain->getIdea(index);
    }
    return "";
}
