/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/08/30 13:48:00 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << BBLE << "\t FragTrap Constructor (default) " <<  RESET << std::endl;
	Name = "FragTrap_Nameless";
	(*this).set_FragTrap_val();
	(*this).status();
}

FragTrap::FragTrap(std::string const & src)
{
	std::cout << BBLE << "\t FragTrap Constructor (string) " <<  RESET << std::endl;
	this->Name = src;
	(*this).set_FragTrap_val();
	(*this).status();
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << BBLE << "\t FragTrap Constructor (copy) " <<  RESET << std::endl;
	*this = src;
	(*this).status();
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

void	FragTrap::status(void) const
{
	/*
	std::cout << BBLE << "\t (ᵔᴥᵔ) FragTrap Constructor (ᵔᴥᵔ) " <<  RESET << std::endl;
	std::cout << "FragTrap name [" << this->Name << "]" << std::endl;
	std::cout << "FragTrap hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "FragTrap energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "FragTrap attack_damage [" << this->attack_damage << "]" << std::endl;

	*/
}

FragTrap::~FragTrap()
{
	std::cout << BBLE << "\t FragTrap Destruction " <<  RESET << std::endl;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap model [ " << this->Name << " ] 🙌 wants to HIGH_FIVE you 🙌 !" << std::endl;
}