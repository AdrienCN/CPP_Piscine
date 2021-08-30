/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 19:51:22 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << BYLW << "\tScavTrap Constructor (default)" <<  RESET << std::endl;
	Name = "Nameless";
	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(std::string const & src)
{
	std::cout << BYLW << "\tScavTrap Constructor (string)" <<  RESET << std::endl;
	this->Name = src;
	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << BYLW << "\tScavTrap Constructor (copy)" <<  RESET << std::endl;
	*this = src;
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
	hit_point = 100; //ClapTrap::hit_point ou this->hit_point
	energy_point = 50;
	attack_damage = 20;
}

void	ScavTrap::s_status(void) const
{
	std::cout << UNDERLINE << "ScavTrap [" << this->Name << "] status :" << RESET << std::endl;
	std::cout << "ScavTrap hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "ScavTrap energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "ScavTrap attack_damage [" << this->attack_damage << "]" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BYLW << "\t - - ScavTrap Destruction - -" <<  RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap model [ " << this->Name << " ] Holds the DOOR" << std::endl;
}
