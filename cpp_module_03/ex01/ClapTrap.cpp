/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:46:19 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 11:46:21 by aldinc42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
	}
    return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and dies!" << std::endl;
	}
	else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " hit points!" << std::endl;
}
