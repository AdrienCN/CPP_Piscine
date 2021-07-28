/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:33:28 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 11:37:27 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	Karen	Karen;

	if (argc != 2)
	{
		std::cerr << "Error : manager : format : \"program_name\" \"complain\"\n";
		return (1);
	}
	Karen.complain(argv[1]);
	return (0);
}
