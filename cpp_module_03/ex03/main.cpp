/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:48:23 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 12:25:11 by aldinc42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Testing DiamondTrap - Multiple Inheritance ===" << std::endl;
    DiamondTrap diamond("Diamond");
    
    std::cout << "\n=== Testing DiamondTrap attributes ===" << std::endl;
    std::cout << "DiamondTrap should have:" << std::endl;
    std::cout << "- Hit points from FragTrap (100)" << std::endl;
    std::cout << "- Energy points from ScavTrap (50)" << std::endl;
    std::cout << "- Attack damage from FragTrap (30)" << std::endl;
    std::cout << "- Attack method from ScavTrap" << std::endl;
    
    std::cout << "\n=== Testing DiamondTrap attack (should use ScavTrap's attack) ===" << std::endl;
    diamond.attack("Enemy");
    
    std::cout << "\n=== Testing inherited methods ===" << std::endl;
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    
    std::cout << "\n=== Testing inherited special abilities ===" << std::endl;
    diamond.guardGate();        // This ability is from ScavTrap
    diamond.highFivesGuys();    // This ability is from FragTrap
    
    std::cout << "\n=== Testing DiamondTrap's own special ability ===" << std::endl;
    diamond.whoAmI();
    
    std::cout << "\n=== Testing construction/destruction chaining ===" << std::endl;
    {
        std::cout << "Creating another DiamondTrap..." << std::endl;
        DiamondTrap test("Test");
        test.whoAmI();
        std::cout << "Leaving scope..." << std::endl;
    }
    
    std::cout << "\n=== End of main - Destructor calls ===" << std::endl;
    return 0;
}
