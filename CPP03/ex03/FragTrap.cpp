/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:47:24 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 17:27:55 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Nameless_FragTrap")
{
	std::cout << BBLE  << "\t[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "\t  FragTrap constructor (DEFAULT)" <<  RESET << std::endl;
	(*this).set_FragTrap_val();
}

FragTrap::FragTrap(std::string const & src) : ClapTrap(src)
{
	std::cout << BBLE  << "\t[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "\t  FragTrap constructor (STRING)" <<  RESET << std::endl;
	(*this).set_FragTrap_val();
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src.get_name())
{
	std::cout << BBLE  << "\t[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "\t  FragTrap constructor (COPY)" <<  RESET << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	std::cout << BBLE << BOLDOFF << "FragTrap Assignation operator called" << std::endl;
	_Name = src.get_name();
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
	std::cout << UNDERLINE  << BBLE  << BOLDOFF << "FragTrap [" << this->_Name << "] status:" << RESET << std::endl;
	std::cout << "\t_F_: hit_point [" << this->hit_point << "]" << std::endl;
	std::cout << "\t_F_: energy_point [" << this->energy_point << "]" << std::endl;
	std::cout << "\t_F_: attack_damage [" << this->attack_damage << "]" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BBLE  << "\t[" << this->_Name + "]" << BOLDOFF; 
	std::cout << "  * * FragTrap destruction * *" <<  RESET << std::endl;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << BBLE << BOLDOFF;
	std::cout << "FragTrap model [ " << this->_Name << " ] 🙌 wants to HIGH_FIVE you 🙌 !" << std::endl << RESET;
}
