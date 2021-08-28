/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/08/28 10:12:34 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	Name = "Oo_Nameless_oO";
	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(std::string const & src)
{
	this->Name = src;
	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	this->Name = src.get_name();
	(*this).set_ScavTrap_val();
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	Name = src.get_name();
	hit_point = src.get_HP();
	energy_point = src.get_EP();
	attack_damage = src.get_AD();
	return *this;
}

void	ScavTrap::set_ScavTrap_val(void)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	(*this).Scav_status();
}

void	ScavTrap::Scav_status(void) const
{
	std::cout << BYLW << "\t - - ScavTrap Constructor - - " <<  RESET << std::endl;
	std::cout << "ScavTrap name [" << this->Name << "]" << std::endl;
	std::cout << "ScavTrap hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "ScavTrap energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "ScavTrap attack_damage [" << this->attack_damage << "]" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BYLW << "\t - - ScavTrap Destruction - -" <<  RESET << std::endl;
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap model [ " << this->Name << " ] Holds the DOOR" << std::endl;
}

void	ScavTrap::attack(std::string const & target) const 
{
	std::cout << BYLW << Name << RESET << " attacks " << BYLW << target << RESET;
	std::cout << " causing " << attack_damage << " points of damages" << std::endl;}
