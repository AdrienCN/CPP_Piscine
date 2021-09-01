/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:56:22 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:39:40 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define BGREEN "\033[1m\033[32m"
# define RESET "\033[0m"
# define BOLDOFF "\033[22m"
# define UNDERLINE "\033[4m"

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(std::string const & src_name);
					ClapTrap(ClapTrap const & src);
	ClapTrap &		operator=(ClapTrap const & src);
					~ClapTrap();

	void			attack(std::string const & target) const;
	
	std::string  	get_name() const;
	unsigned int	get_HP() const;
	unsigned int	get_EP() const;
	unsigned int	get_AD() const;

	void			set_name(std::string const & src_name);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			status() const;

	protected:
		std::string _Name;
		unsigned int hit_point ;
		unsigned int energy_point ; 
		unsigned int attack_damage ;
};
#endif
