/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:24:52 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/04 14:24:55 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main()
{
	ClapTrap player("ali");

	player.attack("veli");
	player.takeDamage(2);
	player.beRepaired(3);
}
