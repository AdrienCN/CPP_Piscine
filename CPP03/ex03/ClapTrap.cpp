/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:03:44 by calao             #+#    #+#             */
/*   Updated: 2021/08/28 10:29:40 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << BGREEN << "*_* ClapTrap constructor(default) called *_*" << RESET << std::endl;
	this->Name = "nameless";
	(*this).status();
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout <<  BGREEN << "*_* ClapTrap constructor(copy) called" << RESET << std::endl;
	*this = src;
	(*this).status();
}

ClapTrap::ClapTrap(std::string const & src_name)
{
	this->Name = src_name;
	std::cout << BGREEN << "*_* ClapTrap constructor(string) called| " << RESET << std::endl;
	(*this).status();
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	this->Name = src.get_name();
	std::cout << BGREEN << "|*_* ClapTrap constructor(operator) called" << RESET << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] Destructor called"<< std::endl;
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

void	ClapTrap::status(void)
{
	std::cout << "name = " << this->Name << std::endl;
	std::cout << "hit_point = "<< this->hit_point << std::endl;
	std::cout << "attack_damage = "<< this->attack_damage << std::endl;
	std::cout << "energy_point = "<< this->energy_point << std::endl;
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



