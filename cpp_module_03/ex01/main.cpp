/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:25:10 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/04 14:25:12 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap serena("Serena");

    std::cout << "\n=== Testing ScavTrap attack ===" << std::endl;
    serena.attack("Ash");
    
    std::cout << "\n=== Testing take damage ===" << std::endl;
    serena.takeDamage(30);
    
    std::cout << "\n=== Testing repair ===" << std::endl;
    serena.beRepaired(20);
    
    std::cout << "\n=== Testing special ability ===" << std::endl;
    serena.guardGate();
    
    std::cout << "\n=== End of main - Destructor calls ===" << std::endl;
    return 0;
}
