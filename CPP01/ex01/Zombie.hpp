/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:42:01 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 17:08:08 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define BYLW "\033[1m\033[33m"
# define RESET "\033[0m"

class Zombie {

	public:

		Zombie(std::string);
		Zombie(void);
		~Zombie(void);
		void	announce( void );
		void	set_name( std::string name );
	
	private:

		std::string	_name;
};

Zombie *zombieHorde( int N, std::string name);

#endif
