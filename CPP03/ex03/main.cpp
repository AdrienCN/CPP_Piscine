/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:38:34 by calao            ###   ########.fr       */
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
	DiamondTrap a("LOCKLASS");
	DiamondTrap b(a);
	DiamondTrap c = b;
	DiamondTrap d;

	d = a;

	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	d.whoAmI();
	d.attack("A Panda");
/*	DiamondTrap c = b;
	DiamondTrap d;

	d = a;
	d.whoAmI();
	
	DiamondTrap	*test = new DiamondTrap();
	test->whoAmI();
	std::cout << std::endl;
	delete test;

	std::cout << std::endl << "\t\t**************Other Test**********" << std::endl << std::endl;
	DiamondTrap pokemon("Rondoudou");
	pokemon.whoAmI();
	pokemon.attack("Sacha et ses mauvais gouts vestimentaire");
	std::cout << std::endl;
	*/
	return (0);
}
