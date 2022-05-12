/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:30:07 by marvin            #+#    #+#             */
/*   Updated: 2021/12/17 15:22:49 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::ifstream &file, std::ofstream &out, std::string line, std::string s1, std::string s2){
	std::string tmp;

	for (size_t i = 0; i < line.length(); i++)
	{
		tmp = &line[i];
		tmp = tmp.substr(0, s1.length());
		if (!tmp.find(s1))
		{
			out << s2;
			i += s1.length() - 1;
		}
		else
			out << line[i];
	}
	if (!file.eof())
		out << "\n";
}

static int check_argv(std::string archive, std::string s1, std::string s2){
	std::ifstream file;
	std::ofstream out;
	std::string line;

	file.open(archive);
	if (!file.is_open())
		return (1);
	out.open(archive + ".replace", std::ios::trunc);
	if (!out.is_open())
		return (1);
	if (s1.length() == 0 || s2.length() == 0)
		return (1);
	while (std::getline(file, line))
		replace(file, out, line, s1, s2);
	file.close();
	out.close();
	return (0);
}

int	main(int argc, char *argv[]){
	if (argc != 4)
	{
		std::cout << "Error: nº arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	if (check_argv(argv[1], argv[2], argv[3]))
	{
		std::cout << "Error: arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}