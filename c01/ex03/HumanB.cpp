/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:52:16 by calao             #+#    #+#             */
/*   Updated: 2021/07/22 14:02:15 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>
HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon)
{
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}
void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
void	HumanB::attack( void ) const
{
	std::cout << this->_name ;
	if (this->_weapon == NULL)
		std::cout << " is unarmed, it is dangerous to fight" << std::endl;
	else
	{
		std::cout << " attacks with his ";
		std::cout << this->_weapon->getType() << std::endl;
	}
	return ;
}
