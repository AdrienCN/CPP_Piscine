/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 22:01:29 by calao            ###   ########.fr       */
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
	DiamondTrap carbon("Rondoudou");

	carbon.whoAmI();
	std::cout << std::endl;
	carbon.attack("an innocent random guy");
	carbon.guardGate();
	carbon.highFivesGuys();

	return (0);
}
