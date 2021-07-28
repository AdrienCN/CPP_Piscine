/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:20:35 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 16:34:39 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	Zombie* heapZombie;
	std::string snape("Snape_from_the_stack");
	std::string harry("Harry_from_the_heap");

	heapZombie = newZombie(harry);
	randomChump(snape);
	
	heapZombie->announce();
	
	delete heapZombie;
	return (0);
}
