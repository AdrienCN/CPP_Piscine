/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:56:22 by calao             #+#    #+#             */
/*   Updated: 2021/08/28 10:03:38 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define BGREEN "\033[1m\033[32m"
# define RESET "\033[0m"

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(std::string const & src_name);
					ClapTrap(ClapTrap const & src);
	ClapTrap &		operator=(ClapTrap const & src);
					~ClapTrap();

	std::string  	get_name() const;
	void			attack(std::string const & target) const;
	unsigned int	get_HP() const;
	unsigned int	get_EP() const;
	unsigned int	get_AD() const;

	void			set_name(std::string const & src_name);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			status();

	protected:
		std::string Name;
		unsigned int hit_point = 10;
		unsigned int energy_point = 10;
		unsigned int attack_damage = 0;
};
#endif
