/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:30:00 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 12:11:38 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone();
        } else {
            templates[i] = 0;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        // Delete current templates
        for (int i = 0; i < 4; i++) {
            delete templates[i];
            templates[i] = 0;
        }
        
        // Deep copy new templates
        for (int i = 0; i < 4; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cout << "Cannot learn null materia" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = materia->clone();
            std::cout << "MateriaSource learned " << materia->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn " << materia->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            std::cout << "MateriaSource creating " << type << std::endl;
            return templates[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know how to create " << type << std::endl;
    return 0;
}
