/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:47:51 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 21:28:42 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define BMAG "\33[1m\33[35m"
#define BRED "\33[1m\33[31m"

class DiamondTrap: public FragTrap, public ScavTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string const & src);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap & operator=(DiamondTrap const & src);

		~DiamondTrap();
		
		void	attack(std::string const & target);
		void		whoAmI() const;
		void		set_diamond_val();
	
	private:
		std::string _Name;
};
#endif
