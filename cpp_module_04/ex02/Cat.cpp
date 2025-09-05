/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:18:24 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 13:48:48 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    CatBrain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    CatBrain = new Brain(*(other.CatBrain)); // Deep copy
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete CatBrain; // delete ex brain
        CatBrain = new Brain(*(other.CatBrain)); // make new brain
    }
    return *this;
}

Cat::~Cat() {
    delete CatBrain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miyav Miyav" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string& idea) {
    if (CatBrain) {
        CatBrain->setIdea(index, idea);
    }
}

std::string Cat::getBrainIdea(int index) const {
    if (CatBrain) {
        return CatBrain->getIdea(index);
    }
    return "";
}
