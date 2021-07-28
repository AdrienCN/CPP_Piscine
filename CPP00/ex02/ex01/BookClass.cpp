/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BookClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:53:53 by calao             #+#    #+#             */
/*   Updated: 2021/07/20 17:01:03 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Book::Book( void )
{
	this->contact_nb = 0;
	return ;
}

Book::~Book( void )
{
	return ;
}

int		Book::exit( void ) const
{
	std::cout << GREEN << "Exiting program." << std::endl << RESET;
	return (0);
}

void	Book::add_contact(std::string& input)
{
	(void)input;
	if (this->contact_nb >= 8)
	{
		std::cout << RED << "\tAdding contact impossible. Phonebook capacity is already full." << std::endl << RESET;
		return ;
	}

	std::cout << "Enter contact informations:\n";
	std::cout << "[first name] : ";
	std::getline (std::cin, this->list[contact_nb].first_name);
	std::cout << "[last name] : ";
	std::getline (std::cin, this->list[contact_nb].last_name);
	std::cout << "[nick name] : ";
	std::getline (std::cin, this->list[contact_nb].nick_name);
	std::cout << "[phone number] : ";
	std::getline (std::cin, this->list[contact_nb].phone_number);
	std::cout << "[darkest secret] : ";
	std::getline (std::cin, this->list[contact_nb].darkest_secret);
	std::cout << GREEN << "New contact ";
	std::cout << BOLDGREEN << this->list[contact_nb].first_name << RESET;
	std::cout << GREEN <<  " successfully added" <<  RESET << std::endl ;
	this->contact_nb += 1;
	return;
}

void	Book::print_contact_list( void )
{
	int i;
	
	i = 0;
	if (this->contact_nb == 0)
	{
		std::cout << RED << "\tPhonebook empty" << std::endl << RESET;
		return ;
	}
	while (i <= this->contact_nb)
	{
		if (i == 0)
		{
			std::cout.width(10);
			std::cout << "index" << "|";
			std::cout.width(10);
			std::cout << "first name" << "|";
			std::cout.width(10);
			std::cout << "last name" << "|";
			std::cout.width(10);
			std::cout << "nick name" << std::endl;
		}
		else
		{

			std::cout.width(10);
			std::cout << i << "|";
			this->print_truncate(this->list[i - 1].first_name);
			std::cout << "|";
			this->print_truncate(this->list[i - 1].last_name);
			std::cout << "|";
			this->print_truncate(this->list[i - 1].nick_name);
			std::cout << std::endl;
		}
		i++;
	}
	this->print_contact_details();
}

void	Book::print_contact_details(void)
{
	std::string input;
	int			index;

	while (1)
	{
		std::cout << "Now, please enter the contact INDEX you are looking for (1 to 8) : ";
		std::getline (std::cin, input);
		if (input == "1" || input == "2" || input == "3" || input == "4" 
				|| input == "5" || input == "6" || input == "7" || input == "8")
		{
			index = std::stoi(input, NULL, 10);
			if (index > this->contact_nb)
				std::cout << RED << "\tSorry there is no contact at this index" <<RESET << std::endl;
			else
			{
				std::cout << "First name : " << std::setw(10) << GREEN;
				std::cout << this->list[index - 1].first_name << std::endl << RESET;
				std::cout << "Last name : " << std::setw(10) << GREEN;
				std::cout << this->list[index - 1].last_name << std::endl << RESET;
				std::cout << "Nick name : " << std::setw(10) << GREEN;
				std::cout << this->list[index - 1].nick_name << std::endl << RESET;
				std::cout << "Phone number : " << std::setw(10) << GREEN;
				std::cout << this->list[index - 1].phone_number << std::endl << RESET;
				std::cout << "Darkest secret : " << std::setw(10) << GREEN;
				std::cout << this->list[index - 1].darkest_secret << std::endl << RESET;
			}
			break;
		}
		else
			std::cout << RED << "\tError: invalid index : press a value between 1 and 8" << RESET << std::endl;

	}
}

void	Book::print_truncate(std::string& str)
{
	std::string output;

	if (str.size() > 10)
		output = str.substr(0, 9) + ".";
	else
		output = str;
	std::cout.width(10);
	std::cout << output;
}
