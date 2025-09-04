/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:47:19 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 12:21:30 by aldinc42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap serena("Serena");

    std::cout << "\n=== Testing ScavTrap attack ===" << std::endl;
    serena.attack("Ash");
    
    std::cout << "\n=== Testing ScavTrap take damage ===" << std::endl;
    serena.takeDamage(30);
    
    std::cout << "\n=== Testing ScavTrap repair ===" << std::endl;
    serena.beRepaired(20);
    
    std::cout << "\n=== Testing ScavTrap special ability ===" << std::endl;
    serena.guardGate();

    std::cout << "\n\n=== Creating FragTrap ===" << std::endl;
    FragTrap clyde("Clyde");

    std::cout << "\n=== Testing FragTrap attack (30 damage) ===" << std::endl;
    clyde.attack("Enemy");
    
    std::cout << "\n=== Testing FragTrap take damage ===" << std::endl;
    clyde.takeDamage(25);
    
    std::cout << "\n=== Testing FragTrap repair ===" << std::endl;
    clyde.beRepaired(15);
    
    std::cout << "\n=== Testing FragTrap special ability ===" << std::endl;
    clyde.highFivesGuys();

    std::cout << "\n=== End of main - Destructor calls ===" << std::endl;
    return 0;
}
