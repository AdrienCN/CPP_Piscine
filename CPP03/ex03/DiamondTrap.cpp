/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:54:34 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 12:01:17 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << BRED << " \t\tO_::_O DiamondTrap constructor (default) O_::_O" << RESET << std::endl;

	this->Name = "Nameless_Diamond";
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(std::string const & src)
{
	std::cout << BRED << " \t\tO_::_O DiamondTrap constructor (string) O_::_O" << RESET << std::endl;
	this->Name = src;
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << BRED << " \t\tO_::_O DiamondTrap constructor (copy) O_::_O" << RESET << std::endl;
	*this = src;
	(*this).whoAmI();
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
	ClapTrap::Name = src.get_name();
	this->Name = src.get_d_name();
	hit_point = src.get_HP();
	energy_point = src.get_EP();
	attack_damage = src.get_AD();
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BRED << " \t\tO_::_O DiamondTrap destructor O_::_O" << RESET << std::endl;
}

void	DiamondTrap::set_diamond_val()
{
	ClapTrap::Name = this->Name + "_clap_name";
	hit_point = 100;
	energy_point = 50;
	attack_damage = 30;
	(*this).whoAmI();
}

std::string	DiamondTrap::get_d_name() const
{
	return this->Name;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "Diamond name = [" << BRED << this->Name + "]" << RESET << std::endl ;
	std::cout << "Claptrap name = [ " << BYLW << FragTrap::Name + "]" << RESET << std::endl;
}
