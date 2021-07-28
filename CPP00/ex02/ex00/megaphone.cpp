/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:25:04 by calao             #+#    #+#             */
/*   Updated: 2021/07/19 19:51:15 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (isalpha(argv[i][j]))
				std::cout << (char)toupper(argv[i][j]);
			else
				std::cout << (char)argv[i][j];
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
