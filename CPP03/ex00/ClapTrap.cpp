/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:03:44 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 17:28:23 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): Name("nameless")
{
	std::cout << "[" << this->Name << "] ";
	std::cout << "ClapTrap constructor (default)" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : Name(src.get_name())
{
	std::cout << "[" << this->Name << "] ";
	std::cout << "ClapTrap constructor (copy)" << std::endl;
}

ClapTrap::ClapTrap(std::string const & src_name) : Name(src_name)
{
	std::cout << "[" << this->Name << "] ";
	std::cout << "ClapTrap constructor (string)" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "Assignement operator called " << std::endl;
	this->Name = src.get_name();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[" <<  this->Name + "] ";
	std::cout << "[ClapTrap] destructor called"<< std::endl;
}

std::string  ClapTrap::get_name(void) const
{
	return this->Name;
}

void	ClapTrap::set_name(std::string const & src_name)
{
	this->Name = src_name;
}

void	ClapTrap::attack(std::string const & target) const
{
	std::cout << "ClapTrap " << this->Name <<  " attacks "  << target;
	std::cout << " causing " <<  this->hit_point << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " takes " <<  amount << " damages..Ouch!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " has been repaired of " << amount <<  " points.. feeling better already!" << std::endl;
}

void ClapTrap::status(void) const
{
	std::cout << UNDERLINE << this->Name << " status :" << RESET << std::endl;
	std::cout << "\thit_point = "<< this->hit_point << std::endl;
	std::cout << "\tenergy_point = "<< this->energy_point << std::endl;
	std::cout << "\tattack_damage = "<< this->attack_damage << std::endl;
}

