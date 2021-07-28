/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:24:18 by calao             #+#    #+#             */
/*   Updated: 2021/07/22 13:54:33 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
	
	public:
						Weapon( void );
						Weapon( std::string type );
						~Weapon( void );
	std::string const	&getType( void ) const;
	void				setType( std::string type );

	private:

	std::string _type;
};

#endif
