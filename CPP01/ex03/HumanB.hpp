/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:39:58 by calao             #+#    #+#             */
/*   Updated: 2021/07/22 14:01:55 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {

	public:

			HumanB(std::string name);
			HumanB(std::string name, Weapon& weapon);
			~HumanB( void );
	void	attack( void )const;
	void	setWeapon(Weapon& weapon);
		
	private:
		
		std::string	_name;
		Weapon*		_weapon;
};

#endif
