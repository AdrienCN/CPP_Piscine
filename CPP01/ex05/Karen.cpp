/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:24:31 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 18:41:10 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen(void)
{
	std::string debug("DEBUG");
	std::string warning("WARNING");
	std::string error("ERROR");
	std::string info("INFO");
	this->ft_list[debug] = &Karen::_debug;
	this->ft_list[warning] = &Karen::_warning;
	this->ft_list[error] = &Karen::_error;
	this->ft_list[info] = &Karen::_info;

	return ;
}

Karen::~Karen(void)
{
	return;
}

void	Karen::complain(std::string level)
{
	if (ft_list[level])
		(this->*ft_list[level])();
	else
		std::cout << "No one understands me!! I want to speak to manager!" << std::endl;
	return ;
}

void		Karen::_debug(void) const
{
	std::cout << "I am a KAAAAAAREEEENNNNNNNNNNNNNNNNNNNNNN" << std::endl;
	return ;
}

void		Karen::_info(void) const
{
	std::cout << "America's number ONE! Mmmmmmmerica! Usa! Usa! USA!" << std::endl;
	return ;
}

void		Karen::_warning(void) const
{
	std::cout << "If you don't treat me as special customer I will start to behave like a child!" << std::endl; 
	return ;
}

void		Karen::_error(void) const
{
	std::cout << "You are treating me like a REGULAR customer, there must be an ERROR!!!" << std::endl;
	return ;
}
