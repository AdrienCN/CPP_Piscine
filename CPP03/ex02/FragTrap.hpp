/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:32:32 by calao             #+#    #+#             */
/*   Updated: 2021/08/28 10:27:10 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

# define BBLE "\033[1m\033[34m"
# define RESET "\033[0m"

class FragTrap: public ClapTrap {


	public:
	
				FragTrap();
				FragTrap(std::string const & src);
				FragTrap(FragTrap const & src);
	FragTrap &	operator=(FragTrap const & src);

				~FragTrap();
		
		void	Frag_status() const;
		void	set_FragTrap_val();
		void	highFivesGuys() const;

	private:

};
#endif
