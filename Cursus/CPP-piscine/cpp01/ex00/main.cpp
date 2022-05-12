/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:57:18 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 22:01:30 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie[3];

	std::cout << "heap" << std::endl;
	zombie[0] = newZombie("FatZombie");
	zombie[0]->announce();
	zombie[1] = newZombie("UglyZombie");
	zombie[1]->announce();
	zombie[2] = newZombie("PrettyZombie");
	zombie[2]->announce();
	for (int i = 0; i < 3; i++)
		delete (zombie[i]);
	std::cout << std::endl;
	std::cout << "Stack" << std::endl;
	randomChump("EasyToKillZombie");
	randomChump("NotSoEasyToKillZombie");
	randomChump("HardToKillZombie");
}