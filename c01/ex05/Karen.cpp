/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:24:31 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 11:33:17 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

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

	for (i = 0; i < level_nb; i++)
	{
		if (this->f_ptr[i]->id == level)
		{
			this->f_ptr[i]->karen_action;
			return;
		}
	}
	std::cout << "I want to speak to manager!" << std::endl;
	return ;
}

void		Karen::debug(void)
{
	std::cout << "I am a KAAAAAAREEEENNNNNNNNNNNNNNNNNNNNNN" << std::endl;
	return ;
}

void		Karen::info(void)
{
	std::cout << "America's number ONE! Mmmmmmmerica! Usa! Usa! USA!" << std::endl;
	return ;
}

void		Karen::warning(void)
{
	std::cout << "If don't treat me as special customer I will start to behave like a child!" << std::endl; 
	return ;
}

void		Karen::error(void)
{
	std::cout << "You are treating me like a REGULAR customer, there must be an ERROR!!!" << std::endl;
	return ;
}
