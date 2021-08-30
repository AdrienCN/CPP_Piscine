/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 19:59:40 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << BBLE << "\tFragTrap constructor (default)" <<  RESET << std::endl;
	Name = "Nameless";
	(*this).set_FragTrap_val();
}

FragTrap::FragTrap(std::string const & src)
{
	std::cout << BBLE << "\tFragTrap constructor (string)" <<  RESET << std::endl;
	this->Name = src;
	(*this).set_FragTrap_val();
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << BBLE << "\tFragTrap constructor (copy)" <<  RESET << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	Name = src.get_name();
	hit_point = src.get_HP();
	energy_point = src.get_EP();
	attack_damage = src.get_AD();
	return *this;
}

void	FragTrap::set_FragTrap_val(void)
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
}

void	FragTrap::f_status(void) const
{
	std::cout << UNDERLINE  << BBLE << "FragTrap [" << this->Name << "] status:" << RESET << std::endl;
	std::cout << "\t*hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "\t*energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "\t*attack_damage [" << this->attack_damage << "]" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BBLE << "\tFragTrap destruction" <<  RESET << std::endl;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap model [ " << this->Name << " ] 🙌 wants to HIGH_FIVE you 🙌 !" << std::endl;
}
