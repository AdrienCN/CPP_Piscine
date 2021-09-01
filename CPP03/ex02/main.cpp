/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:44:23 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	ClapTrap	clap("Robot_Clap");
	ScavTrap	scav("Droid_Scav");
	FragTrap	frag("Cyborg_Frag");
	
	std::cout << std::endl;
	clap.status();
	clap.attack("a PANDA");
	clap.beRepaired(10);
	clap.takeDamage(42);
	std::cout << std::endl;

	std::cout << std::endl;
	scav.status();
	scav.attack("no one");
	scav.guardGate();
	std::cout << std::endl;

	std::cout << std::endl;
	frag.status();
	frag.highFivesGuys();
	std::cout << std::endl;
	
	


	return (0);
}
