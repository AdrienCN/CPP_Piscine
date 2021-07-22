/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:49:19 by calao             #+#    #+#             */
/*   Updated: 2021/07/21 20:02:13 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

int		main(void)
{
	std::string str("HI THIS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "&str       =  " << &str << std::endl;
	std::cout << "stringPTR  =  " << stringPTR << std::endl;
	std::cout << "&stringREF =  " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "***************************" << RESET << std::endl << std::endl;
	std::cout << "str        =  " << str << std::endl;
	std::cout << "*stringPTR =  " << *stringPTR << std::endl;
	std::cout << "stingREF   =  " << stringREF << std::endl;
	return (0);
}	
