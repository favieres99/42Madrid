/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:53:44 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 18:50:04 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

std::string	short_string(std::string src)
{
	if (src.size() > 10)
	{
		src.resize(9);
		src.append(".");
	}
	return (src);
}

void	book_search(Contact book[8], int contactCount, int x)
{
	int	i = 0;
	std::string buf;

	std::cout << "   index  |firstname | lastname | nickname" << std::endl;
	if (x == 2)
		contactCount = 8;
	while (i < contactCount)
	{
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << '|';
		std::cout << std::setw(10);
		std::cout << short_string(book[i].getFirstName());
		std::cout << '|';
		std::cout << std::setw(10);
		std::cout << short_string(book[i].getLastName());
		std::cout << '|';
		std::cout << std::setw(10);
		std::cout << short_string(book[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, buf);
		i = atoi(buf.c_str());
		if (buf.size() == 1 && buf.at(0) >= '0' && buf.at(0) + 1 <= contactCount + '0')
			break ;
		else
			std::cout << "Not a correct index" << std::endl;
	}
	book[i].printAttributes();
}

int	main()
{
	std::string	buf;
	Contact		book[8];
	int			contactCount, x;

	contactCount = 0;
	while (1)
	{
		std::cout << "Phonebook> ";
		std::getline(std::cin, buf);
		if (buf == "EXIT")
			break ;
		else if (buf == "ADD")
		{
			x = 1;
			if (contactCount == 8)
			{
				contactCount = 0;
				x = 2;
			}
			std::cout << "New contact data" << std::endl;
			book[contactCount].setAttributes();
			contactCount++;
		}
		else if (buf == "SEARCH")
		{
			if (!x)
				std::cout << "There are no contacts" << std::endl;
			else
				book_search(book, contactCount, x);
		}
	}
	return (0);
}