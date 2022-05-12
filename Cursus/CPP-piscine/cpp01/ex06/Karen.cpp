/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:05:11 by marvin            #+#    #+#             */
/*   Updated: 2021/12/14 19:05:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(){
}

Karen::~Karen(){
}

void Karen::complain(std::string i){
	std::string str[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Karen::*ptr[4])(void) = 
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	for (size_t x = 0; x < 4; x++)
		if(str[x] == i)
		{
			while (x < 4)
			{
				(this->*ptr[x])();
				x++;
			}
			return ;
		}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}

void Karen::debug ( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \nI just love it!\n" << std::endl;
}

void Karen::info ( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. \nYou don’t put enough! If you did I would not have to ask for it!\n"<< std::endl;
}

void Karen::warning ( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Karen::error ( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}