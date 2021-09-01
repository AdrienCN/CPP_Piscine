/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:32:32 by calao             #+#    #+#             */
/*   Updated: 2021/09/01 17:26:25 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

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
		
		void	status() const;
		void	set_FragTrap_val();
		void	highFivesGuys() const;

	private:

};
#endif
