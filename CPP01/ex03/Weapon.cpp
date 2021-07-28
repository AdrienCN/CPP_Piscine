/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:32:16 by calao             #+#    #+#             */
/*   Updated: 2021/07/22 13:41:25 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	return ;
}

Weapon::Weapon(std::string weapon_type): _type(weapon_type)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string	const &Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( std::string type)
{
	this->_type = type;
	return ;
}
