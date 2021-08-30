/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:54:34 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 10:42:55 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("Nameless_clap_name")
{
	std::cout << BRED << " \t\tO_::_O DiamondTrap construction (default) O_::_O" << RESET << std::endl;
	this->Name = "Nameless_Diamond";
	(*this).announce();
}

/*DiamondTrap::DiamondTrap(std::string const & src) ClapTrap(src + "_clap_name")
{
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
}
*/
DiamondTrap::~DiamondTrap()
{
}

void	DiamondTrap::announce() const
{
	std::cout << "Diamond_trap [" << BRED << this->Name << RESET <<"] aka [ " << BYLW << ScavTrap::Name << RESET << " ]" << std::endl;
}

void	DiamondTrap::whoAmI() const
{
}
