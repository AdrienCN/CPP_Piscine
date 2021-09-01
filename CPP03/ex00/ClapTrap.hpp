/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:56:22 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:46:14 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET "\33[0m"
#define UNDERLINE "\33[4m"

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(std::string const & src_name);
					ClapTrap(ClapTrap const & src);
					~ClapTrap();
	
	ClapTrap &		operator=(ClapTrap const & src);

	std::string  	get_name() const;
	void			set_name(std::string const & src_name);
	
	void			attack(std::string const & target) const;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			status(void) const;

	private:
		std::string Name;
		unsigned int hit_point;
		unsigned int energy_point;
		unsigned int attack_damage;
};
#endif
