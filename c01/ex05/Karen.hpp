/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:20:31 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 13:36:55 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>

class Karen {

	public:
		
		Karen();
		~Karen();
		void	complain( std::string level);

	private:
		void	(Karen::*fptr_debug) (void) const;
		void	(Karen::*fptr_info) (void) const;
		void	(Karen::*fptr_warning) (void) const;
		void	(Karen::*fptr_error) (void) const;

		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;
};
#endif
