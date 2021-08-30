/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 21:54:31 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	ClapTrap pikachu("Pikachu");
	ClapTrap carapuce("Carapuce");

	pikachu.status();
	carapuce.attack("Pikachu");
	pikachu.takeDamage(42);
	carapuce.beRepaired(100);
	return (0);
}
