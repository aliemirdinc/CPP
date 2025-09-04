/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:24:40 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/04 14:24:43 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "Constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage){
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
	}
    return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energy_points - 1 >= 0) {
		std::cout << "ClapTrap " <<this->name << " attacks " << target << ", causing "<< this->attack_damage << " points of damage" << std::endl;
		this->energy_points -= 1;
	}
	else {
		std::cout << "insufficient energy you can not attack" << std::endl;
	}
	
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points - amount >= 0) {
		std::cout << "ClapTrap lost "<< amount << " points of hit points" << std::endl;
		this->hit_points -= amount;
	}
	else
		this->hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points > 0) {
		std::cout << "ClapTrap gained "<< amount << " points of hit points" << std::endl;
		this->hit_points += amount;
	}
	else
		std::cout << "you can not heal, you died" << std::endl;
}
