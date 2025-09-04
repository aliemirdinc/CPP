/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:26:15 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/04 14:26:17 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	//base class name
    std::string name;

public:
	//name of Diamond Trap
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack;
};

#endif
