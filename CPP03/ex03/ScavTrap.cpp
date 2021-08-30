/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 12:06:33 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	Name = "ScavTrap_Nameless";
	(*this).set_ScavTrap_val();
	(*this).status();
}

ScavTrap::ScavTrap(std::string const & src)
{
	this->Name = src;
	(*this).set_ScavTrap_val();
	(*this).status();
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	(*this).status();
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
}

void	ScavTrap::status(void)
{
	/*
	std::cout << BYLW << "\t - - ScavTrap Constructor - - " <<  RESET << std::endl;
	std::cout << "ScavTrap name [" << this->Name << "]" << std::endl;
	std::cout << "ScavTrap hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "ScavTrap energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "ScavTrap attack_damage [" << this->attack_damage << "]" << std::endl;
*/
	}

ScavTrap::~ScavTrap()
{
	std::cout << BYLW << "\t - - ScavTrap Destruction - -" <<  RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap model [ " << this->Name << " ] Holds the DOOR" << std::endl;
}
