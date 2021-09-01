/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:54:34 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 20:06:46 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_trap"), _Name("Nameless_Diamond")
{
	std::cout << BMAG << "\t\t[" << DiamondTrap::_Name << "]" << BOLDOFF;
	std::cout << "  DiamondTrap constructor (default)" << RESET << std::endl;

//	DiamondTrap::_Name = "Nameless_Diamond";
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(std::string const & src)
{
	std::cout << BMAG << " \t\tDiamondTrap constructor (string)" << RESET << std::endl;
	DiamondTrap::_Name = src;
	(*this).set_diamond_val();
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << BMAG << " \t\tDiamondTrap constructor (copy)" << RESET << std::endl;
	*this = src;
	(*this).whoAmI();
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
	std::cout << BRED << "(call to assignation operator)" << std::endl;
	ClapTrap::_Name = src.get_name();
	this->_Name = src.get_d_name();
	hit_point = src.get_HP();
	energy_point = src.get_EP();
	attack_damage = src.get_AD();
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BMAG << " \t\tDiamondTrap destructor" << RESET << std::endl;
}

void	DiamondTrap::set_diamond_val()
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 30;
}

std::string	DiamondTrap::get_d_name() const
{
	return this->_Name;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << BMAG << UNDERLINE << "Who am I ? :" << std::endl;
	std::cout << RESET << BMAG << "\t[" << this->_Name + "]" << RESET;
	std::cout << "  also known as " << BYLW << "[" << ClapTrap::_Name + "]"  << RESET << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
