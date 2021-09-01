/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 16:19:32 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	ClapTrap pikachu("Pikachu_1");
	ClapTrap pikachu2(pikachu);
	ClapTrap pikachu3;
	ClapTrap carapuce("Carapuce");

	pikachu3 = pikachu2;

	pikachu.status();
	carapuce.attack("Pikachu");
	pikachu.takeDamage(42);
	carapuce.beRepaired(100);
	pikachu2.status();
	pikachu3.status();
	return (0);
}
