/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:20:31 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 18:44:32 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>
//#include <map>

class Karen {

	public:
		
		Karen();
		~Karen();
		void	complain( std::string level);

	private:
//		std::map	<std::string, void(Karen::*)(void) const> ft_list;
		void		_debug(void) const;
		void		_info(void) const;
		void		_warning(void) const;
		void		_error(void) const;
};
#endif
