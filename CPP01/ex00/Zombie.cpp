/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:51:12 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 16:37:54 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ): _name(name)
{
	std::cout << "Hello zombie " << BYLW;
	std::cout << this->_name << " .." << RESET << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "Bye bye zombie " << BYLW;
	std::cout << this->_name << ".." << RESET << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout << BYLW << this->_name << RESET;
	std::cout << "  BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
