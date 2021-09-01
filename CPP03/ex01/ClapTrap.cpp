/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:03:44 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 17:28:47 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Nameless")
{
	std::cout << BGREEN << "[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "  ClapTrap constructor (DEFAULT)" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : _Name(src.get_name())
{
	std::cout << BGREEN << "[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "  ClapTrap constructor (COPY)" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string const & src_name) : _Name(src_name)
{
	std::cout << BGREEN << "[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "  ClapTrap constructor (STRING)" << RESET << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	this->_Name = src.get_name();
	std::cout << BGREEN << "[" << this->_Name + "]" << BOLDOFF; 
	std::cout << " ClapTrap Assignation operator called" << RESET << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BGREEN << "[" << this->_Name + "]" << BOLDOFF; 
	std::cout << " ClapTrap destructor called" <<  RESET << std::endl;
}

std::string  ClapTrap::get_name(void) const
{
	return this->_Name;
}

void	ClapTrap::set_name(std::string const & src_name)
{
	this->_Name = src_name;
}

void	ClapTrap::attack(std::string const & target) const
{
	std::cout << BGREEN << BOLDOFF << "Claptrap :  [" << this->_Name <<  "] attacks "  << target;
	std::cout << " causing " <<  this->hit_point << " points of damage!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BGREEN << BOLDOFF;
	std::cout << "ClapTrap :  [" << this->_Name << "] takes " <<  amount << " damages..Ouch!" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << BGREEN << BOLDOFF;
	std::cout << "ClapTrap :  [" << this->_Name << "] has been repaired of " << amount <<  " points.. feeling better already!" << RESET << std::endl;
}

void	ClapTrap::status(void) const
{
	std::cout << BGREEN << BOLDOFF << UNDERLINE << "ClapTrap [" << this->_Name + "] status:" << RESET << std::endl;
	std::cout << "\t_C_: hit_point ["<< this->hit_point << "]" << std::endl;
	std::cout << "\t_C_: energy_point ["<< this->energy_point << "]" << std::endl;
	std::cout << "\t_C_: attack_damage ["<< this->attack_damage << "]" << std::endl;
}

unsigned int ClapTrap::get_EP(void) const
{
	return this->energy_point;
}

unsigned int ClapTrap::get_AD(void) const
{
	return this->attack_damage;
}

unsigned int ClapTrap::get_HP(void) const
{
	return this->hit_point;
}



