/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:45:30 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	ClapTrap clap("Robot_Clap");
	ScavTrap droid("Droid_Scav");
	ScavTrap box("Box_Scav");
	ScavTrap empty;
	ScavTrap copy_box = box;

	std::cout << std::endl;
	clap.status();
	clap.attack("a giant panda in the woods");
	clap.beRepaired(10);
	clap.takeDamage(42);
	std::cout << std::endl;
	
	std::cout << std::endl;
	droid.status();
	droid.attack("innocent guy in the street");
	droid.guardGate();
	std::cout << std::endl;

	return (0);
}
