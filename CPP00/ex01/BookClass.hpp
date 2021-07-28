/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BookClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:51:00 by calao             #+#    #+#             */
/*   Updated: 2021/07/20 16:23:37 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_CLASS_HPP
# define BOOK_CLASS_HPP

#include "phonebook.h"

class Book
{
	public:
		
		Contact		list[8];
		int			contact_nb;

		Book( void );
		~Book( void );

		void	print_contact_list( void );
		int		exit( void ) const;

		void	print_truncate(std::string& str);
		void	print_contact_details( void );
		void	add_contact(std::string& input);
};

#endif
