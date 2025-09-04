/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:48:05 by aldinc42          #+#    #+#             */
/*   Updated: 2025/09/04 12:03:01 by aldinc42         ###   ########.fr       */
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
