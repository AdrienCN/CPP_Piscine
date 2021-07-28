/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:57:24 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 17:21:13 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(int argc, char **argv)
{
	Zombie* Horde;
	int		N;
	int		i;

	if (argc != 3)
	{
		std::cout << "Needs 2 arguments\n";
		return (1);
	}
	std::string name(argv[2]);
	N = std::atoi(argv[1]);
	if (N <= 0)
	{
		std::cout << "Please enter a positive int as arguments one.\n";
		return (1);
	}
	Horde = zombieHorde(N, name); 
	for (i = 0; i < N; i++)
		Horde[i].announce();
	delete[] Horde;
	return (0);
}
