/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:26 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 17:20:19 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *Horde;
	int		i;

	i = 0;
	Horde = new Zombie [N];
	while (i < N)
	{
		Horde[i].set_name(name);
		i++;
	}
	return (Horde);
}
