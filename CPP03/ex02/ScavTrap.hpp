/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:32:32 by calao             #+#    #+#             */
/*   Updated: 2021/08/28 10:08:28 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

# define BYLW "\033[1m\033[33m"
# define RESET "\033[0m"

class ScavTrap: public ClapTrap {


	public:
	
				ScavTrap();
				ScavTrap(std::string const & src);
				ScavTrap(ScavTrap const & src);
	ScavTrap &	operator=(ScavTrap const & src);

				~ScavTrap();
		
		void	Scav_status() const;
		void	attack(std::string const & target) const;
		void	guardGate() const;

		void	set_ScavTrap_val();
	private:

};
#endif
