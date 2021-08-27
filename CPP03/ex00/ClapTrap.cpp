/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:03:44 by calao             #+#    #+#             */
/*   Updated: 2021/08/07 11:24:27 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "**Default** [ClapTrap] constructor called"<< std::endl;
	this->Name = "nameless";
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "**Copy** [ClapTrap] constructor called"<< std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string const & src_name)
{
	std::cout << "**String** [ClapTrap] constructor called"<< std::endl;
	this->Name = src_name;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "**Assignation** [ClapTrap] constructor called"<< std::endl;
	this->Name = src.get_name();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] Destructor called"<< std::endl;
}

std::string & ClapTrap::get_name(void) const
{
	return this->Name;
}

void	ClapTrap::set_name(std::string const & src_name)
{
	this->Name = src_name;
}
