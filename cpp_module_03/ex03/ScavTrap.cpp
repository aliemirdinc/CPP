/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:48:35 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 11:48:36 by aldinc42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no energy points left!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
