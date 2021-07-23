/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:24:31 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 13:37:48 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen(void)
{
	this->fptr_debug = this->_debug;
	return ;
}

Karen::~Karen(void)
{
	return;
}

void	Karen::complain(std::string level)
{
	if (level.compare("DEBUG") == true)
	{
		this->fptr_debug();
		return;
	}
	std::cout << "I want to speak to manager!" << std::endl;
	return ;
}

void		_debug(void)
{
	std::cout << "I am a KAAAAAAREEEENNNNNNNNNNNNNNNNNNNNNN" << std::endl;
	return ;
}

void		_info(void)
{
	std::cout << "America's number ONE! Mmmmmmmerica! Usa! Usa! USA!" << std::endl;
	return ;
}

void		_warning(void)
{
	std::cout << "If don't treat me as special customer I will start to behave like a child!" << std::endl; 
	return ;
}

void		_error(void)
{
	std::cout << "You are treating me like a REGULAR customer, there must be an ERROR!!!" << std::endl;
	return ;
}
