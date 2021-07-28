/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:42:01 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 16:37:41 by calao            ###   ########.fr       */
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
		~Zombie(void);
		void	announce( void );
	
	private:

		std::string	_name;
};

Zombie *newZombie( std::string name);
void	randomChump( std::string name);

#endif
