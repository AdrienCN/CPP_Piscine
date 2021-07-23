/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calao <adconsta@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:52:38 by calao             #+#    #+#             */
/*   Updated: 2021/07/23 11:04:10 by calao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

bool	ft_copy_file(std::ifstream& f_input, std::ofstream& f_output
						, std::string& needle, std::string& new_needle);

int		main(int argc, char **argv)
{	
	std::string		new_filename;
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	f_input;
	std::ofstream	f_output;
	int				i;

	if (argc != 4)
	{
		std::cerr << "Error : usage : 3 arguments needed" <<std::endl;
		return (1);
	}
	
	//Set values 
	
	s1 = argv[2];
	s2 = argv[3];
	filename = argv[1];
	if (filename.empty() == true || s1.empty() == true || s2.empty() == true)
	{
		std::cerr << "Error : Empty string in arguments" << std::endl;
		return (1);
	}
	new_filename = filename; 
	for (i = 0; new_filename[i] != '\0'; i++)
		new_filename[i] = toupper(new_filename[i]);
	new_filename.append(".replace");
	
	f_input.open(filename, std::ios::in);
	if (f_input.is_open() == false)
	{
		std::cerr << "Error : failed to open \"" + filename + "\" ." <<  std::endl;
		return (1);
	}
	f_output.open(new_filename, std::ios::out | std::ios::trunc);
	if (f_output.is_open() == false)
	{
		std::cerr << "Error : failed to open \"" + new_filename + "\" ." <<  std::endl;
		f_input.close();
		return (1);
	}
	
	if (!ft_copy_file(f_input, f_output, s1, s2))
		std::cerr << "Error : failed to copy file" << std::endl;

	f_output.close();
	f_input.close();
	return (0);
}


bool	ft_copy_file(std::ifstream& f_input, std::ofstream& f_output
						, std::string& needle, std::string& new_needle)
{
	std::string haystack;
	std::string	sed_line;
	size_t		f_pos;
	size_t		s_pos;
	
	//Optimiser pour copier le fichier en une seule fois ?
	while (getline (f_input, haystack))
	{
		if (f_input.bad())
			return (false);
		f_pos = 0;	
		s_pos = 0;
		//++: error if read fails
		//++: errors if write fails
		while ((f_pos = haystack.find(needle, s_pos)) != std::string::npos)
		{
			sed_line.append(haystack, s_pos, (f_pos - s_pos));
			sed_line.append(new_needle);
			s_pos = f_pos + needle.size();
		}
		sed_line.append(haystack, s_pos);
		f_output << sed_line << "\n";
		if (f_output.bad())
			return (false);
		sed_line.clear();

	}
	return (true);
}

