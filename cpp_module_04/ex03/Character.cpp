/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:30:00 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 12:11:38 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character " << name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = 0;
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        
        // Delete current inventory
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = 0;
        }
        
        // Deep copy new inventory
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character " << name << " destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "Cannot equip null materia" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    std::cout << name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
    
    if (inventory[idx]) {
        std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = 0; // Don't delete - just remove reference
    } else {
        std::cout << "Slot " << idx << " is already empty" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
    
    if (inventory[idx]) {
        inventory[idx]->use(target);
    } else {
        std::cout << "No materia at slot " << idx << std::endl;
    }
}
