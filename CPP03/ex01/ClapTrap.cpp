/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:03:44 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 19:53:29 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << BGREEN << "ClapTrap constructor (default)" << RESET << std::endl;
	this->Name = "nameless";
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << BGREEN << "ClapTrap constructor (copy)" << RESET << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string const & src_name)
{
	this->Name = src_name;
	std::cout << BGREEN << "ClapTrap constructor (string)" << RESET << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	this->Name = src.get_name();
	std::cout << BGREEN << "ClapTrap constructor (operator)" << RESET << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BGREEN << "[ClapTrap] Destructor called" <<  RESET << std::endl;
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

void	ClapTrap::status(void) const
{
	std::cout << UNDERLINE << "ClapTrap [" << this->Name + "] status:" << RESET << std::endl;
	std::cout << "\thit_point = "<< this->hit_point << std::endl;
	std::cout << "\tattack_damage = "<< this->attack_damage << std::endl;
	std::cout << "\tenergy_point = "<< this->energy_point << std::endl;
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



