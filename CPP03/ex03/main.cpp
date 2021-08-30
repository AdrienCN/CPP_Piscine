/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 11:55:46 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	/*
	FragTrap r2d2("rd2d2");
	FragTrap c3p0("888_" + r2d2.get_name() + "_8888");
	r2d2.highFivesGuys();
	*/
	DiamondTrap diamond;
	DiamondTrap	square("square");
	DiamondTrap copy(square);
	DiamondTrap assignation = square;

	//diamond.status();

	return (0);
}
