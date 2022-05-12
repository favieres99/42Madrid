/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:21:21 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 12:04:27 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *Animals[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}
	std::cout << "DEEP COPY!!" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Dog copy(*(Dog *)Animals[4]);
	for (int i = 0; i < 100; ++i)
	{
		std::cout << copy.getBrain()->getIdea(i) << "    ";
		std::cout << ((Dog *)Animals[4])->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << "-----------------------------"
			  << std::endl;
	for (int i = 0; i < 10; ++i)
		delete Animals[i];
//	system("leaks Animal");
}