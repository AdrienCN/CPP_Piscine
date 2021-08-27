/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:56:22 by calao             #+#    #+#             */
/*   Updated: 2021/08/07 11:23:01 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(std::string const & src_name);
					ClapTrap(ClapTrap const & src);
	ClapTrap &		operator=(ClapTrap const & src);
					~ClapTrap();

	std::string &	get_name() const;
	void			set_name(std::string const & src_name);

	private:
		std::string Name;
		unsigned int hit_point = 10;
		unsigned int energy_point = 10;
		unsigned int attack_damage = 0;
};
