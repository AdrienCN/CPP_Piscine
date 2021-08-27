/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:18:25 by calao             #+#    #+#             */
/*   Updated: 2021/08/27 18:24:54 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::string str("string");
	ClapTrap chaine(str);
	ClapTrap harry("harry");
	ClapTrap sansnom;
	ClapTrap harry_twin(harry);

	sansnom.beRepaired(42);
	harry.attack("Roberto Alagna");
	chaine.takeDamage(13);
	return (0);
}
