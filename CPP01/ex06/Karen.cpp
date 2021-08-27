/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:24:31 by calao             #+#    #+#             */
/*   Updated: 2021/08/27 17:13:52 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen(void)
{
	return ;
}

Karen::~Karen(void)
{
	return;
}

void	Karen::complain(std::string level)
{
	int i;
	std::string tab[4] {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (i = -1; i < 4; i++)
	{
		if (tab[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
		{
			_error();
			break ;
		}
		default:
			std::cout << "No one understands me!! I want to speak to manager!" << std::endl;
	}
	return ;
}

void		Karen::_debug(void) const
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I am a KAAAAAAREEEENNNNNNNNNNNNNNNNNNNNNN" << std::endl;
	return ;
}

void		Karen::_info(void) const
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "America's number ONE! Mmmmmmmerica! Usa! Usa! USA!" << std::endl;
	return ;
}

void		Karen::_warning(void) const
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "If you don't treat me as special customer I will start to behave like a child!" << std::endl; 
	return ;
}

void		Karen::_error(void) const
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "You are treating me like a REGULAR customer, there must be an ERROR!!!" << std::endl;
	return ;
}
