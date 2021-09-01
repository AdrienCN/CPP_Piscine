/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 17:27:13 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Nameless_ScavTrap")
{
	std::cout << BYLW << "\t[" << this->_Name + "]" << BOLDOFF;
	std::cout << BYLW << "  ScavTrap Constructor (DEFAULT)" <<  RESET << std::endl;
	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(std::string const & src): ClapTrap(src)
{
	std::cout << BYLW << "\t[" << this->_Name + "]" << BOLDOFF;
	std::cout << "  ScavTrap Constructor (STRING)" <<  RESET << std::endl;

	(*this).set_ScavTrap_val();
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src.get_name())
{
	std::cout << BYLW << "\t[" << this->_Name + "]" << BOLDOFF;
	std::cout << BYLW << "  ScavTrap Constructor (COPY)" <<  RESET << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << BYLW <<  BOLDOFF << "ScavTrap Assignation operator called" << std::endl;
	_Name = src.get_name();
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

void	ScavTrap::status(void) const
{
	std::cout << std::endl << BYLW  << UNDERLINE << BOLDOFF << "ScavTrap [" << this->_Name << "] status :" << RESET << std::endl;
	std::cout << "\t_S_: hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "\t_S_: energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "\t_S_: attack_damage [" << this->attack_damage << "]" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BYLW << "\t[" << this->_Name + "]" << BOLDOFF;
	std::cout << "  - - ScavTrap Destruction - -" <<  RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << BYLW <<  BOLDOFF << "ScavTrap :  [" << this->_Name << "] Holds the DOOR" << RESET << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << BYLW << BOLDOFF << "Scavtrap :  [" << this->_Name << "] smash smash [" << target << "]" << RESET << std::endl;
}
