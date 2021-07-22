/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:39:58 by calao             #+#    #+#             */
/*   Updated: 2021/07/22 14:02:05 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {

	public:

			HumanA(std::string name, Weapon& weapon);
			~HumanA( void );
	void	attack( void ) const;
		
	private:
		
		std::string	_name;
		Weapon&		_weapon;
};

#endif
