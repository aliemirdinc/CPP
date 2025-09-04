/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:47:08 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 11:47:10 by aldinc42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destructor called!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "FragTrap " << this->name << " has no energy points left!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "FragTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " requests a positive high five! ✋" << std::endl;
}
