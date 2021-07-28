/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:50:27 by calao             #+#    #+#             */
/*   Updated: 2021/07/20 17:20:36 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int		main(void)
{
	std::string		input;
	Book			phonebook;
	
	while (1)
	{
		std::cout << "What would like to do? (ADD, SEARCH, EXIT) : " << BOLDYELLOW;
		std::getline (std::cin, input);
		std::cout << RESET;
		if (!input.compare("EXIT") 
				|| !input.compare("ADD") 
					|| !input.compare("SEARCH"))
		{
			if (input.compare("EXIT") == 0)
				return (phonebook.exit());
			else if (input.compare("ADD") == 0)
				phonebook.add_contact(input);
			else
				phonebook.print_contact_list();
		}
		else
			std::cout << RED << "\tError: type : ADD or SEARCH or EXIT" << RESET << std::endl;
	}
	return (0);
}
