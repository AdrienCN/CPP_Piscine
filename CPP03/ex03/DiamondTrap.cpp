/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:54:34 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:34:05 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_name"), _Name("Nameless_Diamond")
{
	std::cout << BMAG << "\t\t[" << DiamondTrap::_Name << "]" << BOLDOFF;
	std::cout << "  DiamondTrap constructor (default)" << RESET << std::endl;
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(std::string const & src) : ClapTrap(src + "_clap_name"), _Name(src)
{
	std::cout << BMAG << "\t\t[" << DiamondTrap::_Name << "]" << BOLDOFF;
	std::cout << "   DiamondTrap constructor (STRING)" << RESET << std::endl;
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src._Name + "_clap_name"), _Name(src._Name)
{
	std::cout << BMAG << "\t\t[" << DiamondTrap::_Name << "]" << BOLDOFF;
	std::cout << "  DiamondTrap constructor (COPY)" << RESET << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
	std::cout << BMAG << BOLDOFF << "(call to assignation operator)" << RESET << std::endl;
	ClapTrap::_Name = src.get_name();
	this->_Name = src._Name;
	hit_point = src.get_HP();
	energy_point = src.get_EP();
	attack_damage = src.get_AD();
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BMAG << "\t\t[" << DiamondTrap::_Name << "]" << BOLDOFF;
	std::cout << "  DiamondTrap destruction" << RESET << std::endl;
}

void	DiamondTrap::set_diamond_val()
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 30;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << BMAG  << BOLDOFF << UNDERLINE << "Who am I ? :" << std::endl;
	std::cout << RESET << BMAG << "\t[" << this->_Name + "]" << BOLDOFF;
	std::cout << "  also known as " << BYLW << "[" << ClapTrap::_Name + "]"  << RESET << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
